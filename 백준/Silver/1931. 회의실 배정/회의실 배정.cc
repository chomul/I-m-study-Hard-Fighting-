#include <bits/stdc++.h>
using namespace std;

int n, cnt = 0;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	vector<pair<int, int>> vec;

	int a, b;
	
	while (n--)
	{
		cin >> a >> b;
		vec.push_back(make_pair(b, a));
	}

	sort(vec.begin(), vec.end());

	int start = 0;
	
	for (int i = 0; i < vec.size(); i++)
	{
		if (start <= vec[i].second)
		{
			cnt++;
			start = vec[i].first;
		}
	}

	cout << cnt;
	return 0;
}