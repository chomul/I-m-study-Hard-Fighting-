#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, h;
	long long ans = 0;
	stack<int> st;

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> h;
		if (st.empty())
			st.push(h);
		// 생각 전환!!
		// 높은 건물이 쳐다보는 수를 새는 것이 아닌
		// 낮은 건물이 누구한테 보여지는지를 계산
		while (!st.empty() && st.top() <= h)
			st.pop();

		ans += st.size();
		st.push(h);
	}
	
	cout << ans;

	return 0;
}

