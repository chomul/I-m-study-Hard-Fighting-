#include <bits/stdc++.h>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	list<int> li;
	vector<int> result;
	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		li.push_back(i + 1);
	}

	auto cusor = li.begin();
	int cnt = 0;
	while (!li.empty())
	{
		if (cnt == k - 1 && cusor != li.end())
		{
			result.emplace_back(*cusor);
			cusor = li.erase(cusor);
			cnt = 0;
		}
		else
		{
			if (cusor != li.end())
				cusor++;
			else
			{
				cusor = li.begin();
				cnt--;
			}

			cnt++;
		}
	}

	cout << '<';
	for (int i = 0; i < result.size(); i++)
	{
		if (i == result.size() - 1)
			cout << result[i];
		else
		{
			cout << result[i] << ", ";
		}
	}
	cout << '>';
	return 0;
}
