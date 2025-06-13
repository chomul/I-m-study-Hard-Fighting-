#include <string>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

vector<int> solution(int N, vector<int> stages) {
    
    vector<int> answer;
    
    vector<int> cnt(N+2, 0); 
    for (int i = 0; i < stages.size(); i++) 
        cnt[stages[i]]++; 
    

    vector<pair<int, float>> per;
    int totalcnt = stages.size();

    for (int i = 1; i <= N; i++) {
        if (totalcnt == 0)
            per.push_back({i, 0.0f});
        else
            per.push_back({i, static_cast<float>(cnt[i]) / totalcnt});
        totalcnt -= cnt[i];
    }
    
    sort(per.begin(), per.end(),
         [](const pair<int, float>& a, const pair<int, float>& b) {
             if (a.second != b.second)
                 return a.second > b.second;
             else
                 return a.first < b.first;
         });
                                                                                       
    for (int i = 0; i < per.size(); i++) 
    {
        answer.push_back(per[i].first);
    }
    return answer;
}