#include<iostream> 
#include<algorithm> 
#include<vector> 
#include<cmath>
#include<string>
#include <stack>
#include <queue>

using namespace std;

int main() {
	int n;
	cin >> n;
	queue<int> st;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (s == "push") {
			int n;
			cin >> n;
			st.push(n);
		}
		else if (s == "pop") {
			if (st.size() == 0)
				cout << -1 << '\n';
			else { 
				cout << st.front() << '\n';
				st.pop();
			}
		}
		else if (s == "size") {
			cout << st.size() << '\n';
		}
		else if (s == "empty") {
			if (st.size() == 0)
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
		else if (s == "front") {
			if (st.size() == 0)
				cout << -1 << '\n';
			else
				cout << st.front() << '\n';
		}
		else {
			if(st.size() == 0)
				cout << -1 << '\n';
			else 
				cout << st.back() << '\n';
		}
	}
}