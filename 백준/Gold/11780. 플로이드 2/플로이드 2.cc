#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
using namespace std;

int floid[105][105];
int nxt[105][105];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        fill(floid[i], floid[i] + 1 + n, 0x3f3f3f3f);
    for (int i = 1; i <= n; i++) floid[i][i] = 0;

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        floid[a][b] = min(floid[a][b], c);
        nxt[a][b] = b;
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (floid[i][j] > floid[i][k] + floid[k][j])
                {
                    floid[i][j] = floid[i][k] + floid[k][j];
                    nxt[i][j] = nxt[i][k];
                }
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (floid[i][j] == 0x3f3f3f3f)
                cout << 0 << ' ';
            else cout << floid[i][j] << ' ';
        }
        cout << '\n';
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (floid[i][j] == 0 || floid[i][j] == 0x3f3f3f3f)
            {
                cout << 0 << '\n';
                continue;
            }
            vector<int> path;
            int st = i;
            while (st != j)
            {
                path.push_back(st);
                st = nxt[st][j];
            }
            path.push_back(j);
            cout << path.size() << ' ';
            for (auto c : path) cout << c << ' ';
            cout << '\n';
        }
    }

    return 0;
}