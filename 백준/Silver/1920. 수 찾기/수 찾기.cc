#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int n, k, n2;
	vector<int> vec;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> k;
		vec.push_back(k);
	}
	sort(vec.begin(), vec.end());
	cin >> n2;

	for (int i = 0; i < n2; i++)
	{
		cin >> k;
		cout << binary_search(vec.begin(), vec.end(), k) << '\n';
	}


}