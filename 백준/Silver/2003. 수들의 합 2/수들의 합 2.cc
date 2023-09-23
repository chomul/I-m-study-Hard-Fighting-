#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> vec;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m;
	int cnt = 0, tmp;

	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		vec.emplace_back(tmp);
	}

	int start = 0, end = 0, tot = 0;
	for (; start < n; start++)
	{
		while (end < n && tot + vec[end] <= m)
		{
			tot += vec[end];
			end++;
		}
		if (tot == m) cnt++;
		if (end == n) break;
		tot -= vec[start];
	}
	cout << cnt;
}
