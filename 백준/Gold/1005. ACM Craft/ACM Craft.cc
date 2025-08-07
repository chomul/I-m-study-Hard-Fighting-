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

#define CNT 1001

vector<int> adj[CNT];
vector<int> reverse_adj[CNT];
int degree[CNT];
int build_time[CNT];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        for (int i = 0; i < CNT; i++)
        {
            adj[i].clear();
            reverse_adj[i].clear();
            degree[i] = 0;
            build_time[i] = 0;       
        }
        
        int n, k;
        cin >> n >> k;

        for (int i = 1; i <= n; i++)
            cin >> build_time[i];

        while (k--)
        {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            reverse_adj[y].push_back(x);
            degree[y]++;
        }

        int w;
        cin >> w;

        queue<int> q;
        vector<int> result;

        for (int i = 1; i <= n; i++)
            if (degree[i] == 0) q.push(i);

        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            result.push_back(cur);
            for (auto next : adj[cur])
            {
                degree[next]--;
                if (degree[next] == 0) q.push(next);
            }
        }

        vector<int> temp(n + 1, 0);
        for (int i = 1; i <= n; i++)
            if (reverse_adj[i].size() == 0) temp[i] = build_time[i];
        
        for (int i = 1; i < result.size(); i++)
        {
            int max_time = build_time[result[i]];
            for (int j = 0; j < reverse_adj[result[i]].size(); j++)
            {
                max_time = max(max_time, temp[reverse_adj[result[i]][j]] + build_time[result[i]]);
            }
            temp[result[i]] = max_time;
        }

        cout << temp[w] << '\n';
    }

    return 0;
} 