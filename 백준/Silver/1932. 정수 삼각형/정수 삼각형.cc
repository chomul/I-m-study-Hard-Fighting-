#include <bits/stdc++.h>
using namespace std;

int arr[505][505];
int dp[505][505];

int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	int tmp;
	cin >> dp[1][1];

	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cin >> tmp;
			if(j == i)
				dp[i][j] = dp[i - 1][j - 1] + tmp;
			else if(j == 1)
				dp[i][j] = dp[i - 1][j] + tmp;
			else if(i - 1 > 0 && j - 1 > 0)
				dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + tmp;
		}
	}

	int mx = INT_MIN;
	for (int i = 1; i <= n; i++)
	{
		if (mx < dp[n][i])
			mx = dp[n][i];
	}
	cout << mx;
	return 0;
}