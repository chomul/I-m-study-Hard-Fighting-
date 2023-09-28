#include <iostream>
#include <array>
#include <algorithm>
#include <list>
#include <vector>
#include <stack>
#include <math.h>
#include <string>
#include <map>
#include <queue>
#include <cmath>
using namespace std;



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, x;
	cin >> n;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> qu;

	for (int i = 0; i < n; i++)
	{
		cin >> x;
		if (x != 0)
		{
			qu.push({ abs(x), x});
		}
		else if (qu.empty())
		{
			cout  << '0' << '\n';
		}
		else
		{
			cout << qu.top().second << '\n';
			qu.pop();
		}
	}

	return 0;
}

