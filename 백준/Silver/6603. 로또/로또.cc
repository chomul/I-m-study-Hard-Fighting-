#include <bits/stdc++.h>
using namespace std;

int arr[15];
int tot[15];
int k;

void fun(int cnt)
{
	if (cnt == 6)
	{
		for (int i = 0; i < k; i++)
		{
			if (tot[i] == 0) break;
			cout << tot[i] << ' ';
		}
		cout << '\n';
		return;
	}
	
	for (int i = 0; i < k; i++)
	{
		if (tot[cnt - 1] < arr[i])
		{
			tot[cnt] = arr[i];
			fun(cnt + 1);
			tot[cnt] = 0;
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (1)
	{
		cin >> k;

		if (k == 0) break;

		for (int i = 0; i < k; i++)
		{
			cin >> arr[i];
		}

		fun(0);

		fill(arr, arr + k, 0);
		cout << '\n';
	}



	return 0;
}