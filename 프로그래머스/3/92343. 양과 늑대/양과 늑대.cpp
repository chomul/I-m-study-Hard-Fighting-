#include <string>
#include <vector>

using namespace std;

vector<int> tree[18];
int visit[18];
int answer = 0;

void dfs(vector<int> cur_set, vector<int> info)
{
    int sheep = 0;
    int wolf = 0;

    // 현재 집합에 있는 sheep, worl 카운팅
    for (auto cur : cur_set)
    {
        if (info[cur] == 0) sheep++;
        else wolf++;
    }

    if (sheep <= wolf) return;
    answer = max(answer, sheep);

    //    for (auto cur : cur_set) 이거 쓰면 오류 발생 (중간에 push_back, pop_back 해서)
    for (int i = 0; i < cur_set.size(); i++)
    {
        for (auto next : tree[cur_set[i]])
        {
            if (visit[next]) continue;
            visit[next] = 1;
            cur_set.push_back(next);
            dfs(cur_set, info);
            cur_set.pop_back();
            visit[next] = 0;
        }
    }
}


int solution(vector<int> info, vector<vector<int>> edges) {

    for (int i = 0; i < edges.size(); i++)
        tree[edges[i][0]].push_back(edges[i][1]);

    visit[0] = 1;
    dfs({0}, info);
    
    return answer;
}
