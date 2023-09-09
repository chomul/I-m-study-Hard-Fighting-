#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<long long, int>& a, pair<long long, int>& b)
{
	if (a.second != b.second)
		return a.second > b.second;
	return a.first < b.first;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	map<long long, int> ma;
	vector<pair<long long, int>> vec;
	for (int i = 0; i < n; i++)
	{
		long long temp;
		cin >> temp;
		ma[temp]++;
	}

	for (auto i = ma.begin(); i != ma.end(); i++)
	{
		vec.emplace_back(*i);
	}

	sort(vec.begin(), vec.end(), cmp);

	cout << vec[0].first;
	return 0;
}