#include <bits/stdc++.h>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	stack<int> st;
	int n, a, sum = 0;
	cin >> n;

	while (n)
	{
		cin >> a;

		if (a == 0 && !st.empty())
			st.pop();
		else if (a != 0)
			st.push(a);

		n--;
	}

	while (st.size())
	{
		sum += st.top();
		st.pop();
	}
	cout << sum;
	return 0;
}

