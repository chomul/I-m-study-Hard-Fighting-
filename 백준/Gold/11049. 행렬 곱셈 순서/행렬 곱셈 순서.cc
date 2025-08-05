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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    // dp[i][j] = min(dp[i][k] + dp[k+1][j] + p[i-1] * p[k] * p[j])
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0x3f3f3f3f));
    vector<pair<int, int>> matrix;

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        matrix.emplace_back(a, b);
    }

    for (int i = 1; i <= n; i++)
        dp[i][i] = 0;
    
    for (int len = 2; len <= n; len++) 
    {
        for (int i = 1; i <= n - len + 1; i++)
        {
            int j = i + len - 1;

            for (int k = i; k < j; k++)
            {
                int cost = dp[i][k] + dp[k + 1][j] + matrix[i - 1].first * matrix[k - 1].second * matrix[j - 1].second;
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }

    cout << dp[1][n] << '\n';
    
    return 0;
} 