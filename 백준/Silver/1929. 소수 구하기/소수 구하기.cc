#include <bits/stdc++.h>
using namespace std;

bool isprime(int n)
{
	if (n == 1) return 0;
	for (int i = 2; i * i <= n; i++)
		if (n % i == 0) return 0;

	return 1;
}

int n, m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = n; i <= m; i++)
	{
		if(isprime(i)) cout << i << '\n';
	}
	
	return 0;
}
