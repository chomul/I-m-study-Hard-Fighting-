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
#include <algorithm>

using namespace std;

int dp[501][501];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
vector<vector<int>> graph;

int dfs(int x, int y, int n, int m)
{
    if (x == n - 1 && y == m - 1)
        return 1;

    if (dp[x][y] != -1)
        return dp[x][y];

    dp[x][y] = 0;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if (graph[x][y] <= graph[nx][ny]) continue;
        dp[x][y] += dfs(nx, ny, n, m);        
    }
    return dp[x][y];   
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    graph.assign(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> graph[i][j];
            dp[i][j] = -1;
        }   
    }

    cout << dfs(0, 0, n, m) << endl;    
    
    return 0;
} 