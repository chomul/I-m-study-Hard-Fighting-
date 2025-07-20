#include <string>
#include <vector>

using namespace std;


vector<int> visit;
int answer;
                     /* 탐험한 던전수 */
void explore(int cur_k, int cnt , vector<vector<int>> dungeons)
{
    int chk = 0;
    for (int i = 0; i < visit.size(); i++)
        chk += visit[i];
    answer = max(answer, chk);

    for (int i = 0; i < dungeons.size(); i++)
    {
        int cur_dungeon_k = dungeons[i][0];
        int cur_dungeon_v = dungeons[i][1];

        // 백트래킹
        if (cur_k < cur_dungeon_k) continue;
        if (visit[i]) continue;

        visit[i] = 1;
        explore(cur_k - cur_dungeon_v, cnt + 1, dungeons);
        visit[i] = 0;
    }
    return;
}

int solution(int k, vector<vector<int>> dungeons)
{
    for(int i = 0; i < dungeons.size(); i++)
        visit.emplace_back(0);

    explore(k, 0, dungeons);
    
    return answer;
}
