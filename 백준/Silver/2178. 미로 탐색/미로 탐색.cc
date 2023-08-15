#include <bits/stdc++.h>
using namespace std;

int vis[102][102];
int arr[102][102];
string temp[102];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	
	queue<pair<int, int> > Q;

	for (int i = 0; i < n; i++)
		cin >> temp[i];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			arr[i][j] = int(temp[i][j]) - '0';
		}
	}


	Q.push(make_pair(0, 0));  // 첫 방문 위치 기준점
	vis[0][0] = 1;

	while (!Q.empty())
	{
		pair<int, int> cur = Q.front();
		Q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (vis[nx][ny] || arr[nx][ny] != 1) continue;
			if(vis[nx][ny] != 0)
				vis[nx][ny] = min(vis[nx][ny], vis[cur.first][cur.second] + 1);
			else
				vis[nx][ny] = vis[cur.first][cur.second] + 1;
			Q.push({ nx,ny });

		}
	}

	cout << vis[n - 1][m - 1];

	return 0;
}

