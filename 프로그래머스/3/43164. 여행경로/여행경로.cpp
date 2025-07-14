#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<string> answer;
vector<vector<string>> test;

void dfs(string start, unordered_map<string, vector<pair<string, bool>>>& map, int use_cnt, int ticket_cnt)
{
    if (use_cnt == ticket_cnt)
    {
        test.emplace_back(answer);

        return;
    }
    sort(map[start].begin(), map[start].end(), [](const pair<string, bool>& a, const pair<string, bool>& b) {return a.first < b.first;});
    
    for (int i = 0; i < map[start].size(); i++ )
    {
        if (map[start][i].second == true) continue;
        map[start][i].second = true;
        answer.emplace_back(map[start][i].first);
        dfs(map[start][i].first, map, use_cnt + 1, ticket_cnt);
        map[start][i].second = false;
        answer.pop_back();       
    }
}

vector<string> solution(vector<vector<string>> tickets) {   
    unordered_map<string, vector<pair<string, bool>>> map;

    for (auto ticket : tickets)
        map[ticket[0]].emplace_back(ticket[1], false);
    
    answer.emplace_back("ICN");
    dfs("ICN", map, 0, tickets.size());
    return test[0];
}