#include <bits/stdc++.h>
using namespace std;

int arr[10];
int tot[10];
int n, m;

void fun(int cnt)
{
	if (cnt == m)
	{
		for (int i = 0; i < m; i++)
		{
			if (tot[i] == 0) break;
			cout << tot[i] << ' ';
		}
		cout << '\n';
		return;
	}
	
	for (int i = 1; i <= n; i++)
	{
		if (tot[cnt - 1] <= i)
		{
			tot[cnt] = i;
			fun(cnt + 1);
			tot[cnt] = 0;
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		arr[i - 1] = i;
	}

	fun(0);

	return 0;
}