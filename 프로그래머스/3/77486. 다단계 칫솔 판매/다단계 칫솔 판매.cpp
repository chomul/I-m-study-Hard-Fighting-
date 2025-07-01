#include <string>
#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount)
{
    vector<int> answer;

    unordered_map<string, pair<int, int>> data;
    for (int i = 0; i < enroll.size(); i++)
        data.insert({enroll[i],{i, 0}});

    
    for (int i = 0; i < seller.size(); i++)
    {
        string currname = seller[i];
        int currmoney = amount[i] * 100;
        
        while (true)
        {
            if (currmoney == 0) break;
            if (referral[data[currname].first] == "-")
            {
                data[currname].second += ceil(currmoney * 0.9);
                break;
            }

            data[currname].second += ceil(currmoney * 0.9);
            currname = referral[data[currname].first];
            currmoney = currmoney - ceil(currmoney * 0.9);
        }
    }

    for (auto name : enroll)
        answer.emplace_back(data[name].second);
    
    return answer;
}
