#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	while (n--)
	{
		stack<char> st;
		string s;
		cin >> s;

		for (auto c : s)
		{
			if (!st.empty())
			{
				if (c == ')' && st.top() == '(')
				{
					st.pop();
				}
				else
					st.push(c);
			}
			else
				st.push(c);
		}

		if (!st.empty())
			cout << "NO" << '\n';
		else
			cout << "YES" << '\n';
	}


	return 0;
}

