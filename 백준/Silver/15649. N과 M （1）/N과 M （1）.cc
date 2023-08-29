#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];
bool isused[10];

void fun(int k)
{
	if (k == m)
	{
		for (int i = 0; i < m; i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = 1; i <= n; i++)      // 중요!!!! 백 트래킹의 핵심
	{
		if (!isused[i])
		{
			arr[k] = i;
			isused[i] = true;             
			fun(k + 1);
			isused[i] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	fun(0);

	return 0;
}