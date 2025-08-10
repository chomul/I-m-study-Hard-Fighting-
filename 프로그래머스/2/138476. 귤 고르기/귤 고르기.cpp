#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;

    unordered_map<int, int> map;
    for (int i = 0; i < tangerine.size(); i++)
    {
        map[tangerine[i]]++;
    }
    vector<pair<int,int>> vec(map.begin(), map.end());
    sort(vec.begin(), vec.end(), [](const pair<int,int>& a, const pair<int,int>& b)
    {
        return a.second > b.second;
    });
    int sum = k;
    for (int i = 0; i < vec.size(); i++)
    {
        if (sum - vec[i].second > 0)
        {
            sum -= vec[i].second;
            answer++;
        }
        else
        {
            answer++;
            break;       
        }
    }
    return answer;
}
