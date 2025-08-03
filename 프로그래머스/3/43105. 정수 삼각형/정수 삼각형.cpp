#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    vector<vector<int>> dp = triangle;

    for (int i = 1; i < triangle.size(); i++)
    {
        for (int j = 0; j < triangle[i].size(); j++)
        {
            if (j == 0) dp[i][j] = triangle[i][j] + dp[i - 1][j];
            else if (j == triangle[i].size() - 1) dp[i][j] = triangle[i][j] + dp[i - 1][j - 1];
            else dp[i][j] = triangle[i][j] + max(dp[i - 1][j], dp[i - 1][j - 1]);
        }
    }
    
    return *max_element(dp[dp.size() - 1].begin(), dp[dp.size() - 1].end());
}