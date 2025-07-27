#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<pair<int, int>> divisor_pairs(int n)
{
    vector<pair<int, int>> divisors;
    
    for (int i = 1; i <= sqrt(n); i++)
        if (n % i == 0)
            divisors.push_back(make_pair(i, n / i));

    return divisors;
}

vector<int> solution(int brown, int yellow) {
    vector<int> answer;

    int sum = brown + yellow;
    vector<pair<int, int>> divisors_sum = divisor_pairs(sum);
    vector<pair<int, int>> divisors_yellow = divisor_pairs(yellow);
    for (auto total: divisors_sum)
    {
        for (auto y_total : divisors_yellow)
        {
            if (total.first - 2 >= y_total.first && total.second - 2 >= y_total.second)
            {
                answer.push_back(total.second);
                answer.push_back(total.first);
                return answer;
            }
        }
    }
}