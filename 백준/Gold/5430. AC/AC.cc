#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	deque<int> dq;
	string s, temp;
	int n, m;
	cin >> n;

	while (n--)
	{
		cin >> s >> m >> temp;
		
		// 문자열 입력 받은것에서 숫자만 출력하여 저장
		int cnt = 0;
		for (int i = 1; i < temp.size(); i++)
		{
			if (temp[i] >= '0' && temp[i] <= '9')
			{
				cnt = cnt * 10 + (temp[i] - '0');
			}
			else
			{
				if(cnt != 0)
					dq.push_back(cnt);
				cnt = 0;
			}
		}

		// 문제 실행
		bool error = false, rever = false;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == 'R')
			{
				rever = !rever;
			}
			else if (s[i] == 'D')
			{
				if (dq.empty())
				{
					error = true;
					break;
				}
				else 
				{
					if (rever)
						dq.pop_back();
					else
						dq.pop_front();
				}
			}
		}

		// 정답 출력
		if (error)
			cout << "error\n";
		else
		{
			if (rever) reverse(dq.begin(), dq.end());

			cout << '[';

			while (!dq.empty())
			{
				if (dq.size() == 1)
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
