#include <bits/stdc++.h>
using namespace std;

void fun(int k, int start, int end)
{
	if (k == 1)  // 1개의 칸만 남았을 경우
	{
		cout << start << ' ' << end << '\n';  // 1 번째 칸이 start -> end로 이동
		return;
	}

	fun(k - 1, start, 6 - start - end);   // n-1 번째까지 칸이 2번째 장대로 이통
	cout << start << ' ' << end << '\n';  // n 번째 칸이 start -> end로 이동
	fun(k - 1, 6 - start - end, end);     // n-1 번째까지 칸이 2번째 장대에서 3번째 장대로 이동
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int k;
	cin >> k;

	cout << (1 << k) - 1 << '\n';         // 점화식 등비수열 이용 (1<<k)는 제곱 이용한 것
	fun(k, 1, 3);

	return 0;
}