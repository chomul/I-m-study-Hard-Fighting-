#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	vector<int> a;
	vector<int> b;
	int tmp, sum = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		a.emplace_back(tmp);
	}
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		b.emplace_back(tmp);
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	for (int i = 0; i < n; i++)
	{
		sum += a[i] * b[n - 1 - i];
	}
	cout << sum;

	return 0;
}
