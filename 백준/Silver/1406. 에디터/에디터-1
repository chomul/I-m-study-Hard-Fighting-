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
	list<char> li;

	auto cusor = li.end();

	for (int i = 0; i < s.length(); i++)
	{
		li.push_back(s[i]);
	}

	cin >> m;

	while (m)
	{
		cin >> c;
		switch (c)
		{
		case L:
			if(cusor != li.begin())
				cusor--;
			break;
		case D:
			if(cusor != li.end())
				cusor++;
			break;
		case B:
			if (cusor != li.begin())
			{
				cusor--;
				cusor = li.erase(cusor);
			}
			break;
		case P:
			cin >> d;
			li.insert(cusor, d);
			break;
		default:
			break;
		}

		m--;
	}

	for (auto c: li)
	{
		cout << c;
	}

	return 0;
}

