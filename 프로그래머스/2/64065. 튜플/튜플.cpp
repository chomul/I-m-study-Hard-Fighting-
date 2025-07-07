#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<int> solution(string s) {

    vector<int> answer;

    unordered_map<int, int> cnt_map;
    vector<pair<int, int>> v;
    string str;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '{')
            continue;
        else if (isdigit(s[i]))
        {
            str += s[i];
        }
        else if (s[i] == ',' || s[i] == '}')
        {
            if (!str.empty())
            {
                cnt_map[stoi(str)]++;
                str.clear();
            }
        }
    }

    for (auto c : cnt_map)
        v.push_back({c.first, c.second});

    sort(v.begin(), v.end(), [](const pair<int, int>& a, const pair<int, int>& b)
    {
        return a.second > b.second;
    });

    for (auto c : v)
        answer.push_back(c.first);
    
    return answer;
}