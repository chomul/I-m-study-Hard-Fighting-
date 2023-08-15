#include <bits/stdc++.h>
using namespace std;

int board[502][502] = { 0 };
bool vis[502][502];
int n = 7, m = 10, cnt = 0, max1= 0, tmp = 0;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
		}
	}

	queue<pair<int, int>> Q;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (board[i][j] == 1 && vis[i][j] == 0)
			{
				Q.push({ i,j });
				vis[i][j] = 1;
				cnt++;
				max1 = 0;

				while (!Q.empty())
				{
					auto cur = Q.front();
					Q.pop();
					max1++;
					for (int dir = 0; dir < 4; dir++)
					{
						int nx = cur.first + dx[dir];
						int ny = cur.second + dy[dir];

						if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue; // 범위 밖일 경우
						if (vis[nx][ny] || board[nx][ny] != 1) continue; // 이미 방문한 칸 or 사용 가능한 칸이 아닐 경우
						vis[nx][ny] = 1;
						Q.push({ nx, ny });
					}
				}
				if(tmp < max1)
					tmp = max1;

			}

		}
	}
	
	cout << cnt << '\n' << tmp;

	return 0;
}