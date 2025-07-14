#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int,int>> adj[52];    // 비용, 정점 번호
const int INF = 0x3f3f3f3f;
int d[52];                        // 최단 거리 테이블

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    int st = 1;
    fill(d,d+N+1,INF);
    for (int i = 0; i < road.size(); i++)
    {
        adj[road[i][0]].push_back({road[i][2], road[i][1]});
        adj[road[i][1]].push_back({road[i][2], road[i][0]});
    }

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
    d[st] = 0;

    pq.push({d[st],st});
    while (!pq.empty())
    {
        auto cur = pq.top();
        pq.pop();

        if (d[cur.second] != cur.first) continue;

        for (auto next : adj[cur.second])
        {
            if (d[next.second] > d[cur.second] + next.first)
            {
                d[next.second] = d[cur.second] + next.first;
                pq.push({d[next.second],next.second});
            }
        }
    }
    for(int i = 1; i <= N; i++)
        if(d[i] <= K) answer++;
    
    return answer;
}