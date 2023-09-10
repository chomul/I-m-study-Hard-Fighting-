#include <iostream>
#include <array>
#include <algorithm>
#include <list>
#include <vector>

using namespace std;


int D[1000001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	D[1] = 0;
	D[2] = 1;
	D[3] = 1;

	for (int i = 4; i <= n; i++)
	{
		D[i] = D[i - 1] + 1;
		if (i % 3 == 0)
		{
			D[i] = min(D[i / 3] + 1, D[i]);
		}

		if (i % 2 == 0)
		{
			D[i] = min(D[i / 2] + 1, D[i]);
		}

	}

	cout << D[n];

	return 0;
}