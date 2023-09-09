#include <bits/stdc++.h>
using namespace std;

long long reverse(long long n)
{
	long long rev = 0;
	while (n)
	{
		rev = rev * 10 + n % 10;
		n /= 10;
	}
	return rev;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	vector<long long> vec;

	while (n--)
	{
		long long tmp;
		cin >> tmp;
		vec.emplace_back(reverse(tmp));
	}

	sort(vec.begin(), vec.end());
	for(auto c : vec)
		cout << c << '\n';
	return 0;
}