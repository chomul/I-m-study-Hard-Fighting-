#include <bits/stdc++.h>
using namespace std;

int board[1002][1002] = { 0 };
int vis[100002];
int n = 7, m = 10, cnt = 0;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	queue<int> Q;
	cin >> n >> m;
	fill(vis, vis + 100001, -1);
	Q.push(n);
	vis[n] = 0;
	while (vis[m] == -1)
	{
		auto cur = Q.front();
		Q.pop();


		for (int nxt : {2 * cur, cur + 1, cur - 1})
		{
			if (nxt < 0 || nxt > 100000) continue;
			if (vis[nxt] != -1) continue;

			Q.push(nxt);
			vis[nxt] = vis[cur] + 1;

		}
	}

	cout << vis[m];
	return 0;
}