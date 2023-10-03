#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
using namespace std;

vector<int> adj[32001];
int deg[32001];
int n, m;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		deg[b]++;
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
		if (result.size() == n)
			for (auto c : result) cout << c << ' ';
	}

    return 0;
}

