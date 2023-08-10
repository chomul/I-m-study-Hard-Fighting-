#include <bits/stdc++.h>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	int m;
	cin >> m;

	while (m)
	{
		stack<char> left, right;
		cin >> s;

		for (int i = 0; i < s.length(); i++)
		{
			if (!left.empty() && s[i] == '<')
			{
				right.push(left.top());
				left.pop();
			}
			else if (!right.empty() && s[i] == '>')
			{
				left.push(right.top());
				right.pop();
			}
			else if (!left.empty() && s[i] == '-')
				left.pop();
			else if(s[i] != '<' && s[i] != '>'&& s[i] != '-')
				left.push(s[i]);
		}

		while (!left.empty())
		{
			right.push(left.top());
			left.pop();
		}
		while (!right.empty())
		{
			cout << right.top();
			right.pop();
		}
		cout << '\n';
		m--;
	}
	
	return 0;
}
