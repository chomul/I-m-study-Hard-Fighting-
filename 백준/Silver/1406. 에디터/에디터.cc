#include <bits/stdc++.h>
using namespace std;

enum edit
{
	L = 'L',
	D = 'D',
	B = 'B',
	P = 'P'
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	int m;
	char c, d;
	cin >> s;
	stack<char> left, right;

	for (int i = 0; i < s.length(); i++)
	{
		left.push(s[i]);
	}

	cin >> m;

	while (m)
	{
		cin >> c;
		switch (c)
		{
		case L:
			if (!left.empty())
			{
				right.push(left.top());
				left.pop();
			}
			break;
		case D:
			if (!right.empty())
			{
				left.push(right.top());
				right.pop();
			}
			break;
		case B:
			if (!left.empty())
				left.pop();
			break;
		case P:
			cin >> d;
			left.push(d);
			break;
		default:
			break;
		}

		m--;
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

	return 0;
}

