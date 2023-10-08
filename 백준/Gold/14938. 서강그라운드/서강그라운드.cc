#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
using namespace std;

int floid[105][105];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, r; 
    cin >> n >> m >> r;
    
    vector<int> item(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> item[i];

    for (int i = 1; i <= n; i++)
        fill(floid[i], floid[i] + 1 + n, 0x3f3f3f3f);
    for (int i = 1; i <= n; i++) floid[i][i] = 0;

    for (int i = 0; i < r; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        floid[a][b] = c;
        floid[b][a] = c;
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
                }
            }
        }
    }

    int msum = -1;
    for (int i = 1; i <= n; i++)
    {
        int sum = item[i];
        for (int j = 1; j <= n; j++)
        {
            if (floid[i][j] == 0 || floid[i][j] == 0x3f3f3f3f) continue;
            if (floid[i][j] <= m)
                sum += item[j];
        }

        if (msum < sum) msum = sum;
    }
    
    cout << msum;
    return 0;
}