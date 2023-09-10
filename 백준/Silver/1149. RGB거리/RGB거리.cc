#include <bits/stdc++.h>
using namespace std;

int arr[1005][3];
int dp[1005][3];

int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2];

	dp[0][0] = arr[0][0];
	dp[0][1] = arr[0][1];
	dp[0][2] = arr[0][2];

	for (int i = 1; i < n; i++)
	{
		dp[i][0] = min(arr[i][0] + dp[i - 1][1], arr[i][0] + dp[i - 1][2]);
		dp[i][1] = min(arr[i][1] + dp[i - 1][0], arr[i][1] + dp[i - 1][2]);
		dp[i][2] = min(arr[i][2] + dp[i - 1][1], arr[i][2] + dp[i - 1][0]);
	}

	cout << *min_element(dp[n - 1], dp[n - 1] + 3);
	return 0;
}