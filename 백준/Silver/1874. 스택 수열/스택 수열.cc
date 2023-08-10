#include <bits/stdc++.h>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, cnt = 1;
	cin >> n;
	vector<int> vec(n+1);
	vector<bool> check;
	stack<int> st;
	st.push(cnt);
	check.emplace_back(true);
	for (int i = 1; i <= n; i++)
	{
		cin >> vec[i];
	}

	for (int i = 1; i <= n; i++)
	{
		while(st.empty() ||vec[i] != st.top())
		{
			cnt++;
			if (cnt > n)
			{
				cout << "NO";
				return 0;
			}

			st.push(cnt);
			check.emplace_back(true);
		}
		st.pop();
		check.emplace_back(false);
	}

	for (auto c : check)
	{
		if (c)
			cout << '+' << '\n';
		else
			cout << '-' << '\n';
	}

	return 0;
}