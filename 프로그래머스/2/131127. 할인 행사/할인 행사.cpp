#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool chk(unordered_map<string, int> map)
{
    for (auto val : map)
        if (val.second > 0) return false;

    return true;
}

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;

    unordered_map<string, int> map;
    for (int i = 0; i < want.size(); i++)
        map.insert(make_pair(want[i], number[i]));

    int cnt = 0;
    for (auto c: number)
        cnt += c;
    
    for (int i = 0; i < discount.size(); i++)
    {   // 남은 할인 날짜보다 사야할 물건 수가 많을 경우
        if ( cnt > discount.size() - i) break;
        
        unordered_map<string, int> temp = map;
        for (int j = i; j < i + cnt; j++)
        {
            if (temp.find(discount[j]) != temp.end()) temp[discount[j]]--;
        }
        if (chk(temp))  answer++;
    }
    return answer;
}