#include <bits/stdc++.h>
using namespace std;

long long fun(long long a, long long b, long long c)
{
	if (b == 0) return 0;
	if (b == 1) return a % c;

	long long temp = fun(a, b / 2, c) % c;
	if (b % 2 == 0) return temp * temp % c;
	return temp * temp % c * a % c;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b, c;
	cin >> a >> b >> c;

	cout << fun(a, b, c);

	return 0;

}