#include<iostream> 
#include<algorithm> 
#include<vector> 
#include<cmath>
#include<string>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<pair<int, int>> arr;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		arr.push_back({ a, b });
	}
	sort(arr.begin(), arr.end());

	for (auto c : arr)
		cout << c.first << " " << c.second << '\n';
}