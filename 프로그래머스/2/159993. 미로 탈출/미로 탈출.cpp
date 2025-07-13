#include <string>
#include <vector>
#include <queue>

using namespace std;


#define X first     // 세로
#define Y second    // 가로
#define SIZE 102

int board[SIZE][SIZE];
int vis[SIZE][SIZE];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int solution(vector<string> maps) {
    int answer = 0;
    
    queue<pair<int,int> > Q;

    // S, O : 1 / L : 2 / E : 3 / X : 0
    for (int i = 0; i < maps.size(); i++)
    {
        for (int j = 0; j < maps[i].size(); j++)
        {
            if (maps[i][j] == 'S')
            {
                board[i + 1][j + 1] = 1;
                vis[i + 1][j + 1] = 1;
                Q.push({i + 1,j + 1});
            }
            else if (maps[i][j] == 'X')
                board[i + 1][j + 1] = 0;
            else if (maps[i][j] == 'O')
                board[i + 1][j + 1] = 1;
            else if (maps[i][j] == 'L')
                board[i + 1][j + 1] = 2;
            else if (maps[i][j] == 'E')
                board[i + 1][j + 1] = 3;
        }
    }
    // 레버 찾는 과정
    while(!Q.empty())
    {
        pair<int,int> cur = Q.front();
        Q.pop();
        if(board[cur.X][cur.Y] == 2)
        {
            int temp = vis[cur.X][cur.Y];
            while(!Q.empty()) Q.pop();
            Q.push({cur.X,cur.Y});
            for (int i = 0; i < SIZE ; i++)
                for (int j = 0; j < SIZE; j++)
                    vis[i][j] = 0;
            vis[cur.X][cur.Y] = temp;
            break;
        }

        for(int dir = 0; dir < 4; dir++){ 
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir]; 
            if(nx <= 0 || nx > maps.size() || ny <= 0 || ny > maps[0].size()) continue; 
            if(vis[nx][ny] || board[nx][ny] == 0) continue;
            vis[nx][ny] = vis[cur.X][cur.Y] + 1;
            Q.push({nx,ny});
        }
    }
    
    
    while(!Q.empty())
    {
        pair<int,int> cur = Q.front();
        Q.pop();
        if(board[cur.X][cur.Y] == 3)
        {
            answer += vis[cur.X][cur.Y] - 1;
            break;
        }

        for(int dir = 0; dir < 4; dir++){ 
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir]; 
            if(nx <= 0 || nx > maps.size() || ny <= 0 || ny > maps[0].size())  continue; 
            if(vis[nx][ny] || board[nx][ny] == 0) continue;
            vis[nx][ny] = vis[cur.X][cur.Y] + 1;
            Q.push({nx,ny});
        }
    }
    
    return answer == 0 ? -1 : answer;
}