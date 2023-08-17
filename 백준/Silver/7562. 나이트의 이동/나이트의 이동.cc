#include <bits/stdc++.h>
using namespace std;

int vis[302][302];
pair<int, int> dxy[8] = { {-2, 1}, {-2, -1}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {1, 2}, {1, -2} };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	while (n--)
	{
		queue<pair<int,int>> Q;

		int L, x, y, lx, ly;
		cin >> L >> x >> y >> lx >> ly;

		for (int i = 0; i < L; i++) 
		{
			fill(vis[i], vis[i] + L, 0);
		}

		Q.push({ x,y });
		vis[x][y] = 1;

		for (int i = 0; i < 8; i++)
		{
			while (!Q.empty())
			{
				pair<int, int> cur = Q.front();
				Q.pop();

				if (vis[lx][ly]) break;

				for (int dir = 0; dir < 8; dir++)
				{
					int nx = cur.first + dxy[dir].first;
					int ny = cur.second + dxy[dir].second;
					if (nx < 0 || nx >= L || ny < 0 || ny >= L) continue;
					if (vis[nx][ny]) continue;
					vis[nx][ny] = vis[cur.first][cur.second] + 1;
					Q.push({ nx,ny });
				}
			}
		}

		cout << vis[lx][ly] - 1 << '\n';

	}

	return 0;
}
