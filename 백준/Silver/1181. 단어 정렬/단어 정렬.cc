#include<iostream> 
#include<algorithm> 
#include<vector> 
#include<cmath>
#include<string>
using namespace std;

bool compare(string a, string b) {
	return a.size() < b.size();
}

int main() {
	int n;
	cin >> n;
	vector<string> arr;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		arr.push_back(s);
	}
	sort(arr.begin(), arr.end());
	arr.erase(unique(arr.begin(), arr.end()), arr.end());
	stable_sort(arr.begin(), arr.end(), compare);
	for (auto c : arr)
		cout << c << '\n';

}