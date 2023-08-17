#include <bits/stdc++.h>
using namespace std;

int board[102][102][102];
int vis[102][102][102];
int dx[6] = { 1,0,0,-1, 0, 0 };
int dy[6] = { 0,1,0,0,-1,0 };
int dz[6] = { 0,0,1,0,0, -1 };

struct coo
{
	int x;
	int y;
	int z;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int m, n, h;
	queue<coo> Q;
	cin >> m >> n >> h;

	for (int k = 0; k < h; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> board[j][i][k];
				if (board[j][i][k] == 1) 	Q.push({ j,i,k });
				if (board[j][i][k] == 0) 	vis[j][i][k] = -1;
			}
		}
	}

	while (!Q.empty())
	{
		auto cur = Q.front();
		Q.pop();

		for (int dir = 0; dir < 6; dir++)
		{
			int nx = cur.x + dx[dir];
			int ny = cur.y + dy[dir];
			int nz = cur.z + dz[dir];

			if (nx < 0 || nx >= m || ny < 0 || ny >= n || nz < 0 || nz >= h) continue;
			if (vis[nx][ny][nz] >= 0) continue;

			vis[nx][ny][nz] = vis[cur.x][cur.y][cur.z] + 1;
			Q.push({ nx, ny, nz });
		}
	}

	int ans = 0;
	for (int k = 0; k < h; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (vis[j][i][k] == -1)
				{
					cout << -1;
					return 0;
				}
				ans = max({ ans, vis[j][i][k] });
			}
		}
	}

	cout << ans;
	return 0;
}