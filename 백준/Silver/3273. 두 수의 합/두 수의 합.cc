#include <bits/stdc++.h>
using namespace std;

// 전역변수로 잡지 않으면 배열의 메모리 초과에러 발생
int arr[100001];
bool sum[2000001];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int n, x, cnt = 0;

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	cin >> x;

	for (int i = 0; i < n; i++)
	{
		if (x - arr[i] > 0)
		{
			if (sum[x - arr[i]] == 1)
				cnt++;
			sum[arr[i]] = 1;
		}
	}

	cout << cnt;
	return 0;
}

