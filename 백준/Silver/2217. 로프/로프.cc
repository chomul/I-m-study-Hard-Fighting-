#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	vector<int> vec;
	int a, tmp = n;
	
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		vec.push_back(a);
	}

	sort(vec.begin(), vec.end());

	for (int i = 0; i < n; i++)
		vec[i] *= tmp--;

	cout << *max_element(vec.begin(), vec.end());

	return 0;
}