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

vector<int> adj[501];
int degree[501];
int time_value[501];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        int cur_time, prev;
        cin >> cur_time >> prev;
        time_value[i] = cur_time;
        while (prev != -1)
        {
            if (prev == -1) break;
            adj[i].push_back(prev);
            degree[prev]++;
            cin >> prev;
        }
    }

    queue<int> q;
    vector<int> result;

    for (int i = 1; i <= n; i++)
        if (degree[i] == 0) q.push(i);

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        result.push_back(cur);
        for (int i = 0; i < adj[cur].size(); i++)
        {
            int next = adj[cur][i];
            degree[next]--;
            if (degree[next] == 0) q.push(next);
        }
    }

    reverse(result.begin(), result.end());

    vector<int> dp(n + 1, 0x3f3f3f3f);
    for (int i = 0; i < result.size(); i++)
    {
        if (adj[result[i]].size() == 0) dp[result[i]] = time_value[result[i]];
        else
        {
            int max_time = 0;
            for (int j = 0; j < adj[result[i]].size(); j++)
            {
                max_time = max(max_time, dp[adj[result[i]][j]]);
            }
            dp[result[i]] = min(dp[result[i]], max_time + time_value[result[i]]);
        }
    }

    for (int i = 1; i <= n; i++)
        cout << dp[i] << "\n";
    
    return 0;
} 