#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <tuple>
#include <vector>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int bfs(vector<vector<int>>& graph, vector<vector<int>> vis, vector<int> virus, int Xsize, int Ysize)
{
    queue<pair<int, int>> q;

    for (int i = 0; i < virus.size(); i++)
    {
        q.push(make_pair(virus[i] / Ysize, virus[i] % Ysize));    
    }

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= Xsize || ny < 0 || ny >= Ysize) continue;
            if (vis[nx][ny]) continue;

            vis[nx][ny] = 2;
            q.emplace(nx, ny);
        }
    }

    int temp = 0;
    for (int i = 0; i < Xsize; i++)
    {
        for (int j = 0; j < Ysize; j++)
        {
            if (vis[i][j] == 0)
                temp++;
        }   
    }
    return temp;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    int answer = 0;
    vector<vector<int>> graph(n);
    vector<vector<int>> vis(n);
    vector<int> empty_graph;
    vector<int> virus_graph;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int temp;
            cin >> temp;
            if (temp == 0) empty_graph.push_back(i * m + j);
            if (temp == 2) virus_graph.push_back(i * m + j);
            graph[i].push_back(temp);
            vis[i].push_back(temp);
        }
    }

    vector<int> visited(empty_graph.size(), 0);
    fill(visited.begin(), visited.begin() + 3, 1);
    do
    {
        for (int i = 0; i < visited.size(); i++)
        {
            if (visited[i] == 1)
            {
                graph[empty_graph[i] / m][empty_graph[i] % m] = 1;
                vis[empty_graph[i] / m][empty_graph[i] % m] = 1;                
            }
        }

        answer = max(answer, bfs(graph, vis, virus_graph, n, m));
                        
        for (int i = 0; i < visited.size(); i++)
        {
            if (visited[i] == 1)
            {
                graph[empty_graph[i] / m][empty_graph[i] % m] = 0;
                vis[empty_graph[i] / m][empty_graph[i] % m] = 0;                
            }
        }
    }
    while (prev_permutation(visited.begin(), visited.end()));

    cout << answer << endl;
    return 0;
}
