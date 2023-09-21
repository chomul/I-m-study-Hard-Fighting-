#include <bits/stdc++.h>
using namespace std;

int a, b;
vector<int> vec, arr, brr;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> a >> b;
	int tmp;
	while (a--)
	{
		cin >> tmp;
		arr.emplace_back(tmp);
	}
	while (b--)
	{
		cin >> tmp;
		brr.emplace_back(tmp);
	}

	sort(brr.begin(), brr.end());
	for (int i = 0; i < arr.size(); i++)
	{
		if (!binary_search(brr.begin(), brr.end(), arr[i]))
			vec.emplace_back(arr[i]);
	}
	
	if (vec.empty())
		cout << 0;
	else
	{
		cout << vec.size() << '\n';
		sort(vec.begin(), vec.end());
		for (auto c : vec)
			cout << c << ' ';
	}
}
