#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> vec;

bool isprime(int n)
{
	if (n == 1) return 0;
	for (int i = 2; i * i <= n; i++)
		if (n % i == 0) return 0;

	return 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	int cnt = 0;

	for (int i = 2; i <= n; i++)
	{
		if (isprime(i))
			vec.emplace_back(i);
	}

	int start = 0, end = 0, tot = 0;
	for (; start < vec.size(); start++)
	{
		while (end < vec.size() && tot + vec[end] <= n)
		{
			tot += vec[end];
			end++;
		}
		if (tot == n) cnt++;
		if (end == vec.size()) break;
		tot -= vec[start];
	}
	cout << cnt;
}
