#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> adg[20001];
int visit[20001];
int INF = 0x3f3f3f3f;
using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;

    for (auto it : edge)
    {
        adg[it[0]].push_back(it[1]);
        adg[it[1]].push_back(it[0]);
    }

    for (int i = 1; i <= n; i++)
        visit[i] = INF;
    
    queue<int> q;
    q.push(1);
    visit[1] = 0;


    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        
        for (auto it : adg[cur])
        {
            if (visit[it] <= visit[cur] + 1) continue;
            visit[it] = visit[cur] + 1;
            q.push(it);
        }
    }
    int max_visit = *max_element(visit + 1, visit + n + 1);
    for (int i = 1; i <= n; i++)
        if (visit[i] == max_visit) answer++;
    
    return answer;
}