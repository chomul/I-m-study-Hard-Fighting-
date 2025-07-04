#include <string>
#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount)
{
    vector<int> answer;

    unordered_map<string, pair<int, int>> data;
    
    for(int i = 0; i < enroll.size(); i++)
        data.insert({enroll[i], {i, 0}});

    for (int i = 0; i < seller.size(); i++)
    {
        string cur_name = seller[i];
        int cur_money = amount[i] * 100;   
        
        while (true)
        {
            if (cur_money <= 0) break;
            if (referral[data[cur_name].first] == "-")
            {
                data[cur_name].second += ceil(cur_money * 0.9);
                break;
            }

            data[cur_name].second += ceil(cur_money * 0.9);
            cur_name = referral[data[cur_name].first];
            cur_money = cur_money - ceil(cur_money * 0.9);            
        }
    }

    for (auto c : enroll)
        answer.push_back(data[c].second);
        
    return answer;
}
