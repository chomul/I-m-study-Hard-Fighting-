#include <bits/stdc++.h>
using namespace std;

int k, n;
vector<int> vec;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> k >> n;
	long long mink = INT_MAX;
	long long tmp;
	long long ans = 0;

	for (int i = 0; i < k; i++)
	{
		cin >> tmp;
		mink = max(mink, tmp);
		vec.emplace_back(tmp);
	}

	long long start = 1, mid, end = mink;
	while (start <= end)
	{
		mid = (start + end) / 2;
		int cnt = 0;
		for (int i = 0; i < k; i++)
		{
			cnt += vec[i] / mid;
		}

		if (cnt >= n)
		{
			start = mid + 1;
			ans = max(ans, mid);
		}
		else
			end = mid - 1;
	}

	cout << ans;
	return 0;
}
