#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> gems)
{
    vector<int> answer(2,0);

    unordered_set<string> gemSet;
    for (auto gem : gems)
        gemSet.insert(gem);

    int count = gemSet.size();
    int minlen = 0x3f3f3f3f;
    int start = 0;
    unordered_map<string, int> gemMap;

    for (int end = 0; end < gems.size(); end++)
    {
        gemMap[gems[end]]++;

        while (gemMap.size() == count)
        {
            if (end - start < minlen)
            {
                minlen = end - start;
                answer[0] = start + 1;
                answer[1] = end + 1;
            }

            gemMap[gems[start]]--;
            if (gemMap[gems[start]] == 0) 
                gemMap.erase(gems[start]);
            start++;
        }
    }
    
    return answer;
}