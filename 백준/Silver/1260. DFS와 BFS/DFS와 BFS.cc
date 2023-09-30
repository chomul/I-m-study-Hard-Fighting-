#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
using namespace std;

vector<int> adg[1001];
bool vis[1001];

void bfs(int n)
{
    queue<int> q;
    q.push(n);
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        if (vis[cur]) continue;
        vis[cur] = true;
        cout << cur << ' ';
        for (int i = 0; i < adg[cur].size(); i++)
        {
            int nxt = adg[cur][i];
            if (vis[nxt]) continue;
            q.push(nxt);
        }
    }
}

void dfs(int n)
{
    stack<int> s;
    s.push(n);
    while (!s.empty())
    {
        int cur = s.top(); 
        s.pop();
        if (vis[cur]) continue;
        vis[cur] = true;

        cout << cur << ' ';
        for (int i = 0; i < adg[cur].size(); i++)
        {
            int nxt = adg[cur][adg[cur].size() - 1 - i];
            if (vis[nxt]) continue;
            s.push(nxt);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, v, a, b;
    cin >> n >> m >> v;

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        adg[a].push_back(b);
        adg[b].push_back(a);
    }

    for (int i = 1; i <= n; i++)
        sort(adg[i].begin(), adg[i].end());
    dfs(v);
    fill(vis, vis + (n + 1), false);
    cout << '\n';
    bfs(v);
}

