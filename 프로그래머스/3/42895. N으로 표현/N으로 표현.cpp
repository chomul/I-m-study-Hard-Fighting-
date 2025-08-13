#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(int N, int number) {
    if (N == number) return 1;

    vector<unordered_set<int>> dp(9);

    for (int i = 1; i <= 8; ++i) 
    {
        int concatenated_n = N;
        for (int k = 1; k < i; ++k) 
            concatenated_n = concatenated_n * 10 + N;

        dp[i].insert(concatenated_n);

        for (int j = 1; j < i; ++j)
        {
            int k = i - j;
            for (int num1 : dp[j]) 
            {
                for (int num2 : dp[k]) 
                {
                    dp[i].insert(num1 + num2);
                    dp[i].insert(num1 - num2);
                    dp[i].insert(num1 * num2);
                    if (num2 != 0) {
                        dp[i].insert(num1 / num2);
                    }
                }
            }
        }

        if (dp[i].count(number)) 
            return i;
    }

    return -1;
}