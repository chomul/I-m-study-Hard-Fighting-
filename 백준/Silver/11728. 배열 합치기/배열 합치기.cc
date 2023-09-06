#include <bits/stdc++.h>
using namespace std;

int n, m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	vector<int> a, b, c;
	
	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		a.emplace_back(tmp);
	}

	for (int i = 0; i < m; i++)
	{
		int tmp;
		cin >> tmp;
		b.emplace_back(tmp);
	}

	int x = 0, y = 0;

	while (1)
	{
		if (x == n)
		{
			for (int i = y; i < m; i++)
				c.emplace_back(b[i]);
			break;
		}
		else if (y == m)
		{
			for (int i = x; i < n; i++)
				c.emplace_back(a[i]);
			break;
		}
		else
		{
			if (a[x] > b[y]) c.emplace_back(b[y++]);
			else c.emplace_back(a[x++]);
		}

	}

	for (auto temp : c)
		cout << temp << ' ';

	return 0;
}