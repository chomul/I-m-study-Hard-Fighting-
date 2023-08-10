#include <bits/stdc++.h>
using namespace std;

int arr[26];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k, cnt = 1;
	cin >> n >> k;

	queue<int> q;
	
	for (int i = 1; i <= n; i++)
	{
		q.push(i);
	}
	cout << '<';
	while (!q.empty())
	{
		for (int i = 1; i < k; i++)
		{
			q.push(q.front());
			q.pop();
		}
		cout << q.front();
		q.pop();
		if (q.size())
		{
			cout << ", ";
;		}
	}
	cout << ">";
	return 0;
}