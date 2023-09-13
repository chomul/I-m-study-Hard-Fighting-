#include <bits/stdc++.h>
using namespace std;


int dp[100001];

int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	int tmp;
	cin >> dp[1];
	for (int i = 2; i <= n; i++)
	{
		cin >> tmp;
		dp[i] = max(dp[i - 1] + tmp, tmp);
	}

	cout << *max_element(dp + 1, dp + n + 1);
	return 0;
}