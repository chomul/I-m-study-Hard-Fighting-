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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k;
    cin >> k;

    while (k--)
    {
        int v, e;
        cin >> v >> e;
        vector<vector<int>> vec(v + 1);
        while (e--)
        {
            int x, y;
            cin >> x >> y;

            vec[x].push_back(y);
            vec[y].push_back(x);            
        }

        vector<int> vis(v + 1, 0);
        queue<int> q;
        bool flag = true;
        
        for (int i = 1; i <= v; i++)
        {
            if (vis[i] != 0) continue;
            
            q.push(i);
            vis[i] = 1;

            while (!q.empty())
            {
                int cur = q.front();
                q.pop();

                for (auto next : vec[cur])
                {
                    if (vis[next] == vis[cur])
                    {
                        flag = false;
                        while (!q.empty()) q.pop();
                        break;
                    }

                    if (vis[next] > 0) continue;
                
                    vis[next] = vis[cur] == 1 ? 2 : 1;
                    q.push(next);
                }
            }
        }
        
        if (flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
} 