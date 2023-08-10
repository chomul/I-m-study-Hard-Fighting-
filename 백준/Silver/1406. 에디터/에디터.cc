#include <bits/stdc++.h>
using namespace std;

int arr[26];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	string ls;
	cin >> ls;
	list<char> li;
	for (auto c : ls)
		li.push_back(c);

	int n;
	cin >> n;
	char a, b;
	auto cusur = li.end();
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		if (a == 'L')
		{
			if (cusur == li.begin())
				continue;
			cusur--;
		}
		else if (a == 'D')
		{
			if (cusur == li.end())
				continue;
			cusur++;
		}
		else if (a == 'B')
		{
			if (cusur == li.begin())
				continue;
			auto tmp = cusur;
			li.erase(--tmp);
		}
		else if (a == 'P')
		{
			cin >> b;
			li.insert(cusur, b);
		}
	}

	for (auto c : li)
		cout << c;
	return 0;
}