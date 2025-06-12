#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int cntasw(vector<int> answers ,vector<int> player)
{
    int cnt = 0;
    for(int i = 0; i < answers.size(); i++)
    {
        int temp = i % player.size();
        if(answers[i] == player[temp]) cnt++;
    }
    return cnt;
}

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    vector<int> player1 = {1,2,3,4,5};
    vector<int> player2 = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> player3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    vector<int> cnt = {cntasw(answers, player1), cntasw(answers, player2), cntasw(answers, player3)};
    int temp = *max_element(cnt.begin(), cnt.end());
    
    for(int i = 0; i < cnt.size(); i++)
    {
        if(temp == cnt[i]) 
            answer.push_back(i+1);
    }
    
    return answer;
}