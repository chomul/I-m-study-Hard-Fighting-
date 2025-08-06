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

    // 물품 n개당 k무게 기대값
    int n, k;
    cin >> n >> k;

    vector<vector<int>> dp(n, vector<int>());
    for (int i = 0; i < n; i++)
    {
        int w, v;
        cin >> w >> v;

        for (int j = 0; j <= k; j++)
        {
            if (i == 0 || j == 0)
            {
                if (w <= j) dp[i].push_back(v);
                else dp[i].push_back(0);
            }
            else
            {
                if (j >= w )
                {
                    int max_value = max(dp[i - 1][j], dp[i - 1][j - w] + v);
                    dp[i].push_back(max_value);
                }
                else dp[i].push_back(dp[i - 1][j]);
            }
        }        
    }
    
    cout << dp[n - 1][k] << endl;
    return 0;
} 