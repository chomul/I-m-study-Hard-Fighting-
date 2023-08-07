#include <iostream>
#include <array>
#include <algorithm>
#include <list>
#include <vector>
#include <string>
#include <map>
//#include <tuple>
//#include <stack>
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
	int zero[41] = { 1,0, };
	int one[41] = { 0,1, };

	for (int i = 0; i < n; i++)
	{
		cin >> m;
		for (int j = 2; j <= m; j++)
		{
			zero[j] = zero[j - 1] + zero[j - 2];
			one[j] = one[j - 1] + one[j - 2];
		}
		cout << zero[m] << " " << one[m] << '\n';
	}

	return 0;
}


