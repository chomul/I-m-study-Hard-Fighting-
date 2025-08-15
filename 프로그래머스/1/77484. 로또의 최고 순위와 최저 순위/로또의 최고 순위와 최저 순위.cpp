#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer(2, 0);

    int cnt = 0;
    int zero_cnt = 0;
    unordered_set<int> win_set(win_nums.begin(), win_nums.end());
    for (int i = 0; i < lottos.size(); i++)
    {
        if (lottos[i] == 0) zero_cnt++;
        if (win_set.find(lottos[i]) != win_set.end())
            cnt++;
    }

    answer[0] = min(7 - (cnt + zero_cnt), 6);
    answer[1] = min(7 - cnt, 6);
    
    return answer;
}