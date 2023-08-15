#include <bits/stdc++.h>
using namespace std;

int vis[100002];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	queue<int> Q;
	int n, m;
	cin >> n >> m;
	fill(vis, vis + 100001, -1);
	Q.push(n);
	vis[n] = 0;

	if (n == m)
	{
		cout << 0;
		return 0;
	}

	while (!Q.empty())
	{
		auto cur = Q.front();
		Q.pop();

		if (vis[m] > 0)
		{
			cout << vis[m];
			return 0;
		}

		for (int nxt : {2 * cur, cur + 1, cur - 1})
		{
			if (nxt < 0 || nxt > 100000) continue;
			if (vis[nxt] != -1) continue;

			Q.push(nxt);
			vis[nxt] = vis[cur] + 1;
		}
	}
	return 0;
}
