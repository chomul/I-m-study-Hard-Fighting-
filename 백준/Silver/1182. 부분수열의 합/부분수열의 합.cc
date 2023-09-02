#include <bits/stdc++.h>
using namespace std;

int arr[21];
int n, s, cnt = 0;

void fun(int k, int tt)
{
	if (k == n)
	{
		if (tt == s)
		{
			cnt++;
		}
		return;
	}

	fun(k + 1, tt + arr[k]);
	fun(k + 1, tt);


}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> s;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	fun(0, 0);

  if(s == 0) cnt--;
  cout << cnt;
	return 0;
}