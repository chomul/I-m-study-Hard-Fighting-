#include <bits/stdc++.h>
using namespace std;

bool cmp(string& a, string& b)
{
	int suma = 0, sumb = 0;

	if (a.size() != b.size())
		return a.size() < b.size();

	for (int i = 0; i < a.size(); i++)
	{
		if(a[i] >= '0' && a[i] <= '9')
			suma += a[i] - '0';
	}

	for (int i = 0; i < b.size(); i++)
	{
		if (b[i] >= '0' && b[i] <= '9')
			sumb += b[i] - '0';
	}

	if (suma != sumb)
		return suma < sumb;

	return a < b;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	vector<string> vec;

	for (int i = 0; i < n; i++)
	{
		string temp;
		cin >> temp;
		vec.emplace_back(temp);
	}

	sort(vec.begin(), vec.end(), cmp);

	for (auto c : vec)
		cout << c << '\n';

	return 0;
}