#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int> > land)
{
    vector<vector<int>> dp = land;

    for (int i = 1; i < land.size(); i++)
    {
        for (int j = 0; j < land[i].size(); j++)
        {
            for (int k = 0; k < 4; k++)
            {
                if (j == k) continue;
                dp[i][j] = max(dp[i][j], dp[i - 1][k] + land[i][j]);
            }
        }
    }   

    return *max_element(dp[land.size() - 1].begin(), dp[land.size() - 1].end());
}