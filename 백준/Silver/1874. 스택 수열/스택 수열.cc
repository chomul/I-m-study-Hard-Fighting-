#include <bits/stdc++.h>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	stack<int> st;
	int n, a, max = 1;
	cin >> n;
	vector<char> vec;

	while (n)
	{
		cin >> a;

		if (!st.empty() && st.top() == a)
		{
			st.pop();
			vec.emplace_back('-');
		}
		else if (max <= a)
		{
			for (int i = max; i <= a; i++)
			{
				st.push(i);
				vec.emplace_back('+');
				max = a + 1;
			}
			vec.emplace_back('-');
			st.pop();
		}
		else
		{
			cout << "NO";
			return 0;
		}

		n--;
	}

	for (auto c : vec)
		cout << c << '\n';
	return 0;
}

