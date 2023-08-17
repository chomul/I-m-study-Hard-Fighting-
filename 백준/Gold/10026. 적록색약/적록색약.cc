#include <bits/stdc++.h>
using namespace std;

char board[102][102];
int vis[102][102];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int bfs(int n);
int cnt = 0;
queue<pair<int, int> > Q;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> board[i][j];

    cout << bfs(n) << ' ';

    for (int i = 0; i < n; i++)
        fill(vis[i], vis[i] + n, 0);

    cnt = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == 'R')
                board[i][j] = 'G';
        }
    }

    cout << bfs(n);

	return 0;
}

int bfs(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!vis[i][j])
            {
                vis[i][j] = 1;
                Q.push({ i,j });
                cnt++;
            }
            else continue;

            while (!Q.empty())
            {
                pair<int, int> cur = Q.front();
                char color = board[cur.first][cur.second];
                Q.pop();

                for (int dir = 0; dir < 4; dir++) {
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if (vis[nx][ny] || board[nx][ny] != color) continue;
                    vis[nx][ny] = 1;
                    Q.push({ nx,ny });
                }
            }
        }
    }

    return cnt;
}
