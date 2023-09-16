#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	vector<int> vec;
	int tmp, sum = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		vec.emplace_back(tmp);
	}
	sort(vec.begin(), vec.end());

	for (int i = 0; i < n; i++)
		sum += vec[i] * (n - i);

	cout << sum;
	return 0;
}
