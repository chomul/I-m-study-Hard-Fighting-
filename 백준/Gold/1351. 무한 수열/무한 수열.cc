#include <iostream>
#include <map>
#include <queue>
#include <tuple>
#include <vector>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

long long n, p, q;
unordered_map<long long, long long> dp;

long long solve(long long n)
{    
    if (n == 0) return 1;

    if (dp.count(n) > 0) return dp[n];

    return dp[n] = solve(n / p) + solve(n / q);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> p >> q;

    cout << solve(n) << "\n";
    return 0;
} 