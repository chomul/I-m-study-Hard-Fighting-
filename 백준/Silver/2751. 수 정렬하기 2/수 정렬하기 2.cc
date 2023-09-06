#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


int main() {
	vector<int> arr;
	int n,a;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		arr.push_back(a);
	}


	sort(arr.begin(), arr.end());

	for (auto c : arr)
		cout << c << '\n';
}