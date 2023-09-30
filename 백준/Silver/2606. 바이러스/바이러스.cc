#include <iostream>
#include <array>
#include <algorithm>
#include <list>
#include <vector>
#include <string>
//#include <map>
//#include <chrono>
//#include <tuple>
#include <stack>
//#include <cassert>
//#include <cstdarg>
using namespace std;

int arr[101][101] = { 0, };
int visited[101];
int cnt = -1;

void dfs(int x, int y)
{
	visited[y] = 1;
	cnt++;
	for (int i = 1; i < x + 1; i++)
	{
		if (visited[i] == 1)
			continue;
		if (arr[y][i] == 0)
			continue;
		dfs(x, i);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, a, b;
	cin >> n >> m;

	for (int i = 1; i <= m; i++)
	{
		cin >> a >> b;
		arr[a][b] = 1;
		arr[b][a] = 1;
	}

	dfs(n, 1);
	cout << cnt;
	return 0;
}
