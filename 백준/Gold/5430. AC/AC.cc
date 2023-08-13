#include <bits/stdc++.h>
using namespace std;

void parse(string& tmp, deque<int>& d) {
	int cur = 0;
	for (int i = 1; i + 1 < tmp.size(); i++)
	{
		if (tmp[i] == ',') {
			d.push_back(cur);
			cur = 0;
		}
		else {
			cur = 10 * cur + (tmp[i] - '0');
		}
	}
	if (cur != 0)
		d.push_back(cur);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	while (n--)
	{
		deque<int> dq;
		string s, ss;
		int k;
		bool error = false, rever = false;
		cin >> s >> k >> ss;

		parse(ss, dq);

		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == 'R')
			{
				rever = !rever;
			}
			else
			{
				if (dq.empty())
				{
					error = true;
					break;
				}
				
				if(!rever) dq.pop_front();
				else dq.pop_back();

			}
		}

		if (error)
			cout << "error" << '\n';
		else
		{
			if(rever) reverse(dq.begin(), dq.end());
			cout << '[';
			while (!dq.empty())
			{
				if(dq.size() == 1)
					cout << dq.front();
				else
					cout << dq.front() << ',';
				dq.pop_front();
			}
			cout << ']' << '\n';
		}

	}

	return 0;
}