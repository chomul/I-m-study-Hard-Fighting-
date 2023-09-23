#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	unordered_set<string> s;
	string a, b;
	while (n--)
	{
		cin >> a >> b;
		if (b == "enter")
			s.insert(a);
		else
			s.erase(a);
	}
	vector<string> ans(s.begin(), s.end());
	sort(ans.begin(), ans.end(), greater<string>());
	for (auto c : ans)
		cout << c << '\n';
}
