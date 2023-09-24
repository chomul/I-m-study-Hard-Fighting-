#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
using namespace std;

int n, m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	
	while (n--)
	{
		cin >> m;
		multiset<int> s;
		char c;
		int tmp;
		for (int i = 0; i < m; i++)
		{
			cin >> c >> tmp;
			if (c == 'I')
				s.insert(tmp);
			else if (tmp == -1)
			{
				if(!s.empty())
					s.erase(s.begin());
			}
			else
			{
				if (!s.empty())
					s.erase(prev(s.end()));
			}
		}

		if (s.empty())
			cout << "EMPTY" << '\n';
		else
			cout << *prev(s.end()) << ' ' << *s.begin() << '\n';
	}
}
