#include <iostream>
#include <array>
#include <algorithm>
#include <list>
#include <vector>
#include <stack>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, temp;
	cin >> n >> m;
	vector<int> vec(n + 1);

	for (int i = 1; i <= n; i++)
	{
		cin >> temp;
		vec[i] = vec[i - 1] + temp;
	}

	for (int j = 0; j < m; j++)
	{
		int a, b;
		cin >> a >> b;
		cout << vec[b] - vec[a - 1] << '\n';
	}

	return 0;
}

