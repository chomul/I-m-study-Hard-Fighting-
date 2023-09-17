#include <bits/stdc++.h>
using namespace std;

int GCD(int a, int b)
{
	if (b == 0) return a;
	return GCD(b, a % b);
}
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	while (n--)
	{
		int tmp;
        long long sum = 0;
		cin >> tmp;
		vector<int> vec;

		for (int i = 0; i < tmp; i++)
		{
			int temp;
			cin >> temp;
			vec.emplace_back(temp);
		}

		for (int i = 0; i < tmp; i++)
			for (int j = 0; j < tmp && i != j; j++)
				sum += GCD(vec[i], vec[j]);

		cout << sum << '\n';
	}

	return 0;
}
