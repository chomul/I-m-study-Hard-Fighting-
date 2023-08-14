#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (1) {
		string s;
		getline(cin, s);
		if (s == ".")
			break;

		stack<int> a;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '(' || s[i] == '[')
				a.push(s[i]);
			if (!a.empty() && (s[i] == ')' || s[i] == ']')) {
				if (s[i] == ')' && a.top() == '(')
					a.pop();
				else if (s[i] == ']' && a.top() == '[')
					a.pop();
				else
					a.push(s[i]);
			}
			else if (a.empty() && (s[i] == ')' || s[i] == ']'))
				a.push(s[i]);

		}

		if (a.empty())
			cout << "yes" << '\n';
		else
			cout << "no" << '\n';
	}


	return 0;
}

