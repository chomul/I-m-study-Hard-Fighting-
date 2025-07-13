#include<vector>
#include<queue>
using namespace std;

#define X first     // 세로
#define Y second    // 가로
#define SIZE 102

int board[SIZE][SIZE];
int vis[SIZE][SIZE];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int solution(vector<vector<int> > maps)
{
    int answer = 0;

    queue<pair<int,int>> q;
    for (int i = 0; i < maps.size(); i++)
        for (int j = 0; j < maps[i].size(); j++)
            board[i + 1][j + 1] = maps[i][j];

    q.push({1,1});
    vis[1][1] = 1;

    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();

        if (cur.X == maps.size() && cur.Y == maps[0].size())
            answer = vis[cur.X][cur.Y];

        for (int i = 0; i < 4; i++)
        {
            int curX = cur.X + dx[i];
            int curY = cur.Y + dy[i];
            if (curX <= 0 || curX > maps.size() || curY <=0 || curY > maps[0].size()) continue;
            if (vis[curX][curY] || board[curX][curY] == 0) continue;
            vis[curX][curY] = vis[cur.X][cur.Y] + 1;
            q.push({curX, curY});
        }
    }
    
    return answer > 0 ? answer : -1;
}
