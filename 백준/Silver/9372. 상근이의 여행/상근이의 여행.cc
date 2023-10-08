#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
using namespace std;

vector<int> p(1003, -1);

int find(int x)
{
    if (p[x] < 0) return x;
    return p[x] = find(p[x]);  // 그래프트를 타고가서 가장 최상위에 있는 것
}

bool is_diff_group(int u, int v)
{
    u = find(u); v = find(v);
    if (u == v) return 0;     // 같은 그룹
    if (p[u] == p[v]) p[u]--;
    if (p[u] < p[v]) p[v] = u;
    else p[u] = v;
    return 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int v, e;
        pair<int, int> edge[20005];
        cin >> v >> e;

        for (int i = 1; i <= e; i++)
        {
            int a, b;
            cin >> a >> b;
            edge[i] = { a, b };
            edge[i+e] = { b, a };
        }

        sort(edge, edge + 2 * e);
        int cnt = 0;
        int ans = 0;
        for (int i = 1; i <= 2 * e; i++)
        {
            int a, b;
            tie(a, b) = edge[i];
            if (!is_diff_group(a, b)) continue;
            ans++;
            cnt++;
            if (cnt == v - 1) break;
        }

        cout << ans << '\n';
        fill(p.begin(), p.end(), -1);
    }
    

    return 0;
}