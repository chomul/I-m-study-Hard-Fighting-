#include <bits/stdc++.h>
using namespace std;

int n, cnt = 0;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	int start = 301;
	vector<pair<int, int>> vec;

	int a, b, c, d;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b >> c >> d;
		vec.emplace_back(100 * a + b, 100 * c + d);
	}
	sort(vec.begin(), vec.end());

	int i = 0;
	while (start <= 1130)
	{
		vector<int> test;

		for (; i < n; i++)
		{
			if (vec[i].first <= start)
				test.emplace_back(vec[i].second);
			else
				break;
		}

		if (test.empty())
		{
			cout << 0;
			return 0;
		}

		sort(test.begin(), test.end(), greater<int>());
		start = test[0];
		cnt++;

	}

	cout << cnt;

	return 0;
}
