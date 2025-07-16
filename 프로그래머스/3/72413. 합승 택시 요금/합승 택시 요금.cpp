#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// 최소 비용 + 가중치 -> BFS(다익스트라) -> 우선순위 큐
const int INF = 0x3f3f3f3f;

vector<int> BFS(int n, int s, vector<vector<int>> fares)
{
    vector<pair<int,int>> adj[202];    // 비용, 정점 번호
    vector<int> costs;                  // 최소 비용

    for (int i = 0; i <= n; i++)
        costs.push_back(INF);

    for (int i = 0; i < fares.size(); i++)
    {
        int start = fares[i][0];
        int end = fares[i][1];
        int cost = fares[i][2];
        adj[start].push_back({cost, end});
        adj[end].push_back({cost, start});
    }

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
    for (int i = 0; i <= n; i++)
        if (costs[i] == INF) costs[i] = 1000000;
    
    return costs;
}


int solution(int n, int s, int a, int b, vector<vector<int>> fares)
{
    vector<int> start = BFS(n, s, fares);
    vector<int> A = BFS(n, a, fares);
    vector<int> B = BFS(n, b, fares);
    
    int answer = INF;
    for (int j = 1; j <= n; ++j)
    {
        int sum = start[j] + A[j] + B[j];
        answer = min(answer, sum);
    }
    
    return answer;
}

