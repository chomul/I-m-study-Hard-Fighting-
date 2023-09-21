#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> vec;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	int tmp;
	while (n--)
	{
		cin >> tmp;
		vec.emplace_back(tmp);
	}
	sort(vec.begin(), vec.end());
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> tmp;
		cout << binary_search(vec.begin(), vec.end(), tmp) << ' ';
	}

}
