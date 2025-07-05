#include <string>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

vector<int> solution(int N, vector<int> stages) {
    

    vector<int> answer;
    vector<pair<int, float>> fail;

    int round_cnt = stages.size();
    for (int i = 1; i <= N; i++)
    {
        if (round_cnt == 0)
        {
             fail.push_back({i, 0});
            continue;
        }


        
        int fail_cnt = 0;

        for (auto c: stages)
            if (c == i) fail_cnt++;
        
        fail.push_back({i, (float)fail_cnt / (float)round_cnt});
        round_cnt -= fail_cnt;
    }

    sort(fail.begin(), fail.end(), [](const pair<int, float>& a, const pair<int, float>& b) { if (a.second == b.second) return a.first < b.first;
        else return a.second > b.second;});

    for (auto c: fail)
        answer.push_back(c.first);
    
    return answer;
}