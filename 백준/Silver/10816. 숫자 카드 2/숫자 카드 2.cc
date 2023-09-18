#include<iostream> 
#include<algorithm> 
#include<vector> 
#include<cmath>
#include<string>
#include <stack>
#include <queue>
#include <deque>
using namespace std;

int main() {
	int n, m, x;
	vector<int> arr;
	vector<int> show;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		arr.push_back(x);
	}
	sort(arr.begin(), arr.end());
	cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> x;
        auto l = lower_bound(arr.begin(), arr.end(), x);
        auto u = upper_bound(arr.begin(), arr.end(), x);
        show.push_back(u-l);
    }
	for (auto c : show)
		cout << c << " ";


}