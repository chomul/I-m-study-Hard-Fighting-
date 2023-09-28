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
using namespace std;



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, x;
	cin >> n;
	priority_queue<int> qu;

	for (int i = 0; i < n; i++)
	{
		cin >> x;
		if (x > 0)
		{
			qu.push(x);
		}
		else if (qu.empty())
		{
			cout  << '0' << '\n';
		}
		else
		{
			cout <<  qu.top() << '\n';
			qu.pop();
		}
	}

	return 0;
}

