#include <bits/stdc++.h>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	int arr[10] = { 0 };

	while (n)
	{
		arr[n % 10]++;
		n /= 10;
	}

	arr[6] = ceil(float(arr[6] + arr[9]) / 2);

	cout << *max_element(arr, arr + 9);

	return 0;

}