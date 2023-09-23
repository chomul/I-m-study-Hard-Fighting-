#include <iostream>
#include <array>
#include <algorithm>
#include <list>
#include <vector>
#include <string>
#include <map>
//#include <chrono>
//#include <tuple>
#include <stack>
//#include <cassert>
//#include <cstdarg>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n;
	string a, b;


	for (int i = 0; i < n; i++)
	{
		map<string, int> arr;
		cin >> m;
		int max = 1;
		for (int j = 0; j < m; j++)
		{
			cin >> a >> b;
			if (arr[b] == 0)
				arr[b] = 1;
			else
				arr[b]++;
		}

		for (auto &it : arr)
		{
			max *= (it.second + 1);
		}

		cout << max - 1 << endl;
	}


	return 0;
}
