#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	vector<int> vec, temp, uni;
	int tmp;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		vec.emplace_back(tmp);
	}
	temp = vec;
	
	sort(temp.begin(), temp.end());
	uni.emplace_back(temp[0]);
	for (int i = 1; i < n; i++)
	{
		if (temp[i - 1] != temp[i])
			uni.emplace_back(temp[i]);
	}

	for (int i = 0; i < n; i++)
		cout << lower_bound(uni.begin(), uni.end(), vec[i]) - uni.begin() << ' ';


	return 0;
}
