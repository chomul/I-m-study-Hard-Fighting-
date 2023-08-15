#include <bits/stdc++.h>
using namespace std;

int board[52][52];
bool vis[52][52];
int n = 7, m = 10, k = 0, cnt, sum = 0;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	queue<pair<int, int>> Q;
	cin >> cnt;
	for (int i = 0; i < cnt; i++)
	{
		cin >> m >> n >> k;
		sum = 0;
		for (int j = 0; j < n; j++)
		{
			for (int h = 0; h < m; h++)
			{
				vis[j][h] = 0;
				board[j][h] = 0;
			}
		}
		for (int j = 0; j < k; j++)
		{
			int a, b;

			cin >> a >> b;
			board[b][a] = 1;
		}

		for (int c = 0; c < n; c++)
		{
			for (int d = 0; d < m; d++)
			{
				if (board[c][d] == 1 && vis[c][d] != 1)
				{
					Q.push({ c,d });
					vis[c][d] = 1;
					sum++;
				}

				while (!Q.empty())
				{
					auto cur = Q.front();
					Q.pop();

					for (int dir = 0; dir < 4; dir++)
					{
						int nx = cur.first + dx[dir];
						int ny = cur.second + dy[dir];

						if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
						if (vis[nx][ny] == 1 || board[nx][ny] == 0) continue;

						vis[nx][ny] = 1;
						Q.push({ nx, ny });
					}
				}
			}
		}
		
		cout << sum << '\n';
	}


	return 0;

}