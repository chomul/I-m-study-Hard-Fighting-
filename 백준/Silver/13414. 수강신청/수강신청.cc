#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
using namespace std;

int n, m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m;
	unordered_map<string, int> s;
	string tmp;
	for(int i = 0; i < m; i++)
	{
		cin >> tmp;
		if (s.count(tmp) == 0)
			s.insert({tmp, i });
		else
		{
			s.erase(tmp);
			s.insert({ tmp, i });
		}
	}
	vector<pair<int, string>> vec;
	for (auto it = s.begin(); it != s.end(); it++)
		vec.emplace_back((*it).second, (*it).first);

	sort(vec.begin(), vec.end());

	for (int i = 0; i < n; i++)
	{
		if (i < vec.size())
			cout << vec[i].second << '\n';
		else
			break;
	}

}
