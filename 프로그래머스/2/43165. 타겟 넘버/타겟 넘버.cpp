#include <string>
#include <vector>

using namespace std;


vector<int> adg[51];
int vis[51];
int answer = 0;

void dfs(vector<int> numbers, int cnt, int sum, int target)
{
    if (static_cast<int>(numbers.size()) == cnt)
    {
        if (sum == target) answer++;
        return;
    }


    for (auto next : adg[cnt + 1])
    {
        if (vis[cnt + 1]) continue;
        vis[cnt + 1] = 1;
        dfs(numbers, cnt + 1, sum + next, target);
        vis[cnt + 1] = 0;
    }

}

int solution(vector<int> numbers, int target) {

    for (int i = 0; i < numbers.size(); i++)
    {
        adg[i + 1].emplace_back(numbers[i]);
        adg[i + 1].emplace_back(-numbers[i]);
    }
    
    dfs(numbers, 0, 0, target);
    return answer;
}
