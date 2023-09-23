#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> vec;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	int tmp;
	for(int i = 0; i < n; i++)
	{
		cin >> tmp;
		vec.emplace_back(tmp);
	}

	int tot = 0;
	int start = 0, end = 0, mn = INT_MAX;
	for (; start < n; start++)
	{
		while (end < n && vec[end] + tot < m)
		{
			tot += vec[end];
			end++;
		}
		if (end == n) break;
		tot -= vec[start];
		mn = min(mn, end - start + 1);
	}
	if (mn == INT_MAX) mn = 0;
	cout << mn;

}
