#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
using namespace std;

int floid[105][105];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        fill(floid[i], floid[i] + 1 + n, 0x3f3f3f3f);   // 기본 무한대 설정
    for (int i = 1; i <= n; i++) floid[i][i] = 0;       // 자기 자신 0 설정

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        floid[a][b] = min(floid[a][b], c);              // min 사용 이유는 문제 조건때문
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {   // min 과 같은 의미이지만 시간상으로 더 유리
                if(floid[i][k] + floid[k][j] < floid[i][j]) floid[i][j] = floid[i][k] + floid[k][j]; 
                // floid[i][j] = min(floid[i][j], floid[i][k] + floid[k][j]);
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (floid[i][j] == 0x3f3f3f3f)            // 무한대 처리
                cout << 0 << ' ';
            else cout << floid[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}