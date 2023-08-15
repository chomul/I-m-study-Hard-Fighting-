#include <bits/stdc++.h>
using namespace std;

int board[1002][1002] = { 0 };
int vis[1002][1002];
int n = 7, m = 10;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	queue<pair<int, int>> Q;
	cin >> m >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 1) 	Q.push({ i,j });
			if (board[i][j] == 0) 	vis[i][j] = -1;
		}
	}

	while (!Q.empty())
	{
		auto cur = Q.front();
		Q.pop();

		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];

			if (nx < 0 || nx > n || ny < 0 || ny > m) continue;
			if (vis[nx][ny] >= 0) continue;

			vis[nx][ny] = vis[cur.first][cur.second] + 1;
			Q.push({ nx, ny });
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (vis[i][j] == -1)
			{
				cout << -1;
				return 0;
			}
			ans = max({ ans, vis[i][j] });
		}
	}

	cout << ans;
	return 0;
}