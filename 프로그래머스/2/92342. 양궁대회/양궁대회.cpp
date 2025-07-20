#include <string>
#include <vector>

using namespace std;


vector<int> peach_info(11);
vector<int> Lion_info(11);
pair<int, vector<int>> max_answer;

// k : 인덱스, n : 남은 화살 수
void dfs(int k, int n , vector<int> cur_info)
{
    if (k == 11)
    {
        // 1~10 점까지 쏘고 남은 화살 처리
        if (n > 0) cur_info[10] += n;
        
        // 점수 종합
        int peach_score = 0;
        int Lion_score = 0;
        
        for (int i = 0; i < 11; i++)
        {
            if (peach_info[i] == 0 && cur_info[i] == 0) continue;
            
            if (peach_info[i] >= cur_info[i] )
            {
                peach_score += (10 - i);
            }
            else if (peach_info[i] < cur_info[i])
            {
                Lion_score += (10 - i);
            }
        }

        int score_diff = Lion_score - peach_score;

        if (score_diff > max_answer.first)
            max_answer = {score_diff, cur_info};
        else if (score_diff == max_answer.first && score_diff > 0) // 낮은 점수를 많이 맞춘 경우를 선택
        {
            for (int i = 10; i >= 0; --i) {
                if (cur_info[i] > max_answer.second[i]) {
                    max_answer = {score_diff, cur_info};
                    break;
                } else if (cur_info[i] < max_answer.second[i]) {
                    break;
                }
            }
        }
        return;
    }

    // 피치보다 한발 더 쏠 수 있는 화살이 남아있을 경우
    int temp = peach_info[k] + 1;
    if (temp <= n)
    {
        cur_info[k] = temp;
        dfs(k + 1, n - temp, cur_info);
        cur_info[k] = 0;
    }

    // 해당 점수를 포기하는 경우 (해당 점수 0발)
    dfs(k + 1, n, cur_info);       
    
    return;
}

vector<int> solution(int n, vector<int> info) {

    for (int i = 0; i < info.size(); i++)
        peach_info[i] = info[i];

    dfs(0,n, Lion_info);
    
    return max_answer.second.empty() ? vector<int>{-1} : max_answer.second ;
}
