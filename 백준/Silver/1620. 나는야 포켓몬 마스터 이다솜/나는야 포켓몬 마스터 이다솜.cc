#include <iostream>
#include <array>
#include <algorithm>
#include <list>
#include <vector>
#include <string>
#include <map>

using namespace std;



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	map<int, string> arr;
	map<string, int> arr2;
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		arr.insert({ i, s});
		arr2.insert({ s, i});
	}

	string name;
	for (int i = 0; i < m; i++) {
		cin >> name;
		if ('0' <= name[0] && name[0] <= '9') {
			int output = stoi(name);
			cout << arr[output] << '\n';
		}
		else
		{
			cout << arr2[name] << '\n';
		}
	}

	return 0;
}


