#include<iostream> 
#include<algorithm> 
#include<vector> 
#include<cmath>
#include<string>
using namespace std;

bool compare(pair<int, string> a, pair<int, string> b) {
	return a.first < b.first;
}

int main() {
	int n;
	cin >> n;
	vector<pair<int, string>> arr;
	for (int i = 0; i < n; i++) {
		int a;
		string b;
		cin >> a >> b;
		arr.push_back({ a, b });
	}
	stable_sort(arr.begin(), arr.end(), compare);
		
	for (auto c : arr)
		cout << c.first << " " << c.second << '\n';

}