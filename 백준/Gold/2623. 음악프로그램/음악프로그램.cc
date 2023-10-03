#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
using namespace std;

vector<int> adj[1001];
int deg[1001];
int n, m;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int cnt;
		cin >> cnt;
		vector<int> vec(cnt);
		for (int j = 0; j < cnt; j++)
			cin >> vec[j];

		for (int j = 0; j < cnt - 1; j++)
		{
			adj[vec[j]].push_back(vec[j + 1]);
			deg[vec[j + 1]]++;
		}
	}

	queue<int> q;
	vector<int> result;
	for (int i = 1; i <= n; i++)    
		if (deg[i] == 0) q.push(i);
	while (!q.empty())
	{
		int cur = q.front(); q.pop();
		result.push_back(cur);     
		for (int nxt : adj[cur])     
		{
			deg[nxt]--;               
			if (deg[nxt] == 0) q.push(nxt);
		}
	}
	if (result.size() == n)
		for (auto c : result) cout << c << '\n';
	else
		cout << 0;

    return 0;
}

