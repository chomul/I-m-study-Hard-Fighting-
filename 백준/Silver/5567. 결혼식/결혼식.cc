#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
using namespace std;

vector<int> adg[1001];
int vis[1001];

void bfs(int n)
{
    queue<int> q;
    q.push(n);
    vis[n] = 0;
    int pre = vis[n];
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        if (vis[cur] > 2) continue;

        for (int i = 0; i < adg[cur].size(); i++)
        {
            int nxt = adg[cur][i];
            if (vis[nxt] != 500) continue;
            q.push(nxt);
            vis[nxt] = min(vis[nxt], vis[cur] + 1);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, a, b;
    cin >> n >> m ;

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        adg[a].push_back(b);
        adg[b].push_back(a);
    }
    fill(vis + 1, vis + n + 2, 500);
    bfs(1);
    int cnt = 0;
    for (int i = 2; i <= n; i++)
        if (vis[i] <= 2) cnt++;
    cout << cnt;
}

