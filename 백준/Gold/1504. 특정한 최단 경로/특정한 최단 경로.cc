#include <functional>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// 최소 비용 + 가중치 -> BFS(다익스트라) -> 우선순위 큐
vector<pair<int,int>> adj[802];    // 비용, 정점 번호
const int INF = 0x3f3f3f3f;

vector<int> BFS(int n, int s)
{
    vector<int> costs;                  // 최소 비용

    for (int i = 0; i <= n; i++)
        costs.push_back(INF);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    costs[s] = 0;
    pq.push({costs[s], s});

    while (!pq.empty())
    {
        pair<int, int> cur = pq.top();
        pq.pop();
        if (cur.first != costs[cur.second]) continue;

        for (auto next : adj[cur.second])
        {
            if (costs[next.second] <= cur.first + next.first) continue;
            costs[next.second] = cur.first + next.first;
            pq.push({costs[next.second], next.second});
        }
    }
    
    return costs;
}


int main(int argc, char* argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, e;
    cin >> n >> e;

    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }

    int v1, v2;
    cin >> v1 >> v2;

    vector<int> start = BFS(n, 1);
    vector<int> vec_v1 = BFS(n, v1);
    vector<int> vec_v2 = BFS(n, v2);

    if (start[v1] == INF || start[v2] == INF || vec_v1[v2] == INF || vec_v2[v1] == INF || vec_v1[n] == INF || vec_v2[n] == INF) cout << -1;
    else cout << min(start[v1] + vec_v1[v2] + vec_v2[n], start[v2] + vec_v2[v1] + vec_v1[n]);
    return 0;
}
