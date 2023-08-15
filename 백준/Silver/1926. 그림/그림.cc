#include <bits/stdc++.h>
using namespace std;

int vis[502][502];
int arr[502][502];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	int cnt = 0, mx = 0;
	int maxS = 0;
	queue<pair<int, int> > Q;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j] == 1 && vis[i][j] == 0) // 방문안한거 첫 방문 Start
			{
				cnt++;
				Q.push(make_pair(i, j));  // 첫 방문 위치 기준점
				vis[i][j] = 1;

				while (!Q.empty())
				{
					pair<int, int> cur = Q.front();
					Q.pop();
					mx++;

					for (int dir = 0; dir < 4; dir++) {
						int nx = cur.first + dx[dir];
						int ny = cur.second + dy[dir];
						if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
						if (vis[nx][ny] || arr[nx][ny] != 1) continue;
						vis[nx][ny] = 1;
						Q.push({ nx,ny });

					}
				}
				maxS = max(mx, maxS);
				mx = 0;
			}
		}
	}

	cout << cnt << '\n' << maxS;

	return 0;
}

