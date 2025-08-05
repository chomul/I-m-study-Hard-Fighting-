#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;


int solution(vector<string> strs, string t)
{
    unordered_set<string> str_set(strs.begin(), strs.end());
    //목표 문자열 t의 i번째 글자까지 만드는데 필요한 단어 조각의 최소 개수
    vector<int> dp(t.size() + 1, 0x3f3f3f3f);
    dp[0] = 0;

    for (int i = 1; i <= t.size(); i++)
    {
        int temp = i - 5 >= 0 ? i - 5 : 0;
        for (int j = temp; j < i; j++)
        {
            string s = t.substr(j, i - j);
            if (str_set.find(t.substr(j, i - j)) != str_set.end())
            {
                dp[i] = min(dp[i], dp[j] + 1);
            }
        }
    }
    
    return dp[t.size()] != 0x3f3f3f3f ? dp[t.size()] : -1;
}