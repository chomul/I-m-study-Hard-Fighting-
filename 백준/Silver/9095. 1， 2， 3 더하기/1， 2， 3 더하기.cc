#include <bits/stdc++.h>
using namespace std;

int d[15];
int T, n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;

	while (T--)
	{
		cin >> n;

		d[1] = 1;
		d[2] = 2;
		d[3] = 4;

		for (int i = 4; i <= n; i++)
			d[i] = d[i - 1]	+ d[i - 2] + d[i - 3] ;

		cout << d[n] << '\n';
	}

	return 0;
}