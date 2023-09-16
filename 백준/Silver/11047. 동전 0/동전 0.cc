#include <bits/stdc++.h>
using namespace std;

int n, k, cnt = 0;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;

	vector<int> vec;

	while (n--)
	{
		int tmp;
		cin >> tmp;
		vec.push_back(tmp);
	}

	for (int i = vec.size() - 1; i >= 0; i--)
	{
		if (k >= vec[i])
		{
			cnt += k / vec[i];
			k %= vec[i];
		}
	}

	cout << cnt;
	return 0;
}