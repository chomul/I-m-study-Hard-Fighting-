#include <bits/stdc++.h>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	stack<pair<int, int>> st;
	st.push({ 100000001, 0 });
	for (int i = 1; i <= n; i++)
	{
		int height;
		cin >> height;

		while (st.top().first < height)
			st.pop();
		cout << st.top().second << " ";
		st.push({ height, i });
	}

	return 0;
}