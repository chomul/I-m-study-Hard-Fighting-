#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	deque<int> dq;
	int n, m, cnt = 0, del;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		dq.push_back(i);
	}

	while (m--)
	{
		cin >> del;

		auto location = find(dq.begin(), dq.end(), del) - dq.begin();

		while (dq.front() != del)
		{
			if (location < dq.size() - location)
			{
				dq.push_back(dq.front());
				dq.pop_front();
				cnt++;
			}
			else
			{
				dq.push_front(dq.back());
				dq.pop_back();
				cnt++;
			}
		}
		dq.pop_front();
	}
	cout << cnt;

	return 0;
}

