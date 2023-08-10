#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	queue<int> qu;
	int n;

	cin >> n;

	for (int i = 1; i <= n; i++) 
		qu.push(i);
	
	while (qu.size() != 1)
	{
		qu.pop();
		qu.push(qu.front());
		qu.pop();
	}

	cout << qu.front();

	return 0;
}

