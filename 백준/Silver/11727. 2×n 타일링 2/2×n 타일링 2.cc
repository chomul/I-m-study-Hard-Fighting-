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

	int n;
	cin >> n;
	vector<int> vec(n + 1);
	vec[1] = 1;
	vec[2] = 3;

	for (int i = 3; i <= n; i++)
	{
		vec[i] = vec[i - 1] + vec[i - 2] * 2;
		vec[i] %= 10007;
	}

	cout << vec[n];


	return 0;
}

