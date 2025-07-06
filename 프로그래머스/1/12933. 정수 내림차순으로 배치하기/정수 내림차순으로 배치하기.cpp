#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

long long solution(long long n) {
    long long answer = n;
    vector<int> num;
    while(answer)
    {
        num.emplace_back(answer%10);
        answer /= 10;
    }
    sort(num.begin(), num.end());
    answer = 0;
    for(int i = 0; i < num.size(); i++)
    {
        answer += num[i]*pow(10, i);
    }
    
    return answer;
}