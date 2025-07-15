#include <string>
#include <vector>
#include <cmath>

using namespace std;

// dfs 이용
// bfs 는 최단 경로이지만 현재는 최단경로가 아니라
// 중간 경로에 따른 도로 건설 값이 필요하기 때문에 길을 추적할 수 있는
// dfs 방식을 사용

int board[26][26];
int cost[26][26][4];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int answer = 0x3f3f3f3f;
int corner_cost = 500;
int line_cost = 100;

// board, 현재 위치, 2: 아무 방향 무관 1: 가로방향 0: 세로방향
void dfs(vector<vector<int>>& board, int board_size, int cur_x, int cur_y, int cur_value, int direction) 
{
    if (cur_value > answer) return;
    if (cur_x == board_size - 1 && cur_y == board_size - 1)
    {
        answer = min(cur_value, answer);
        return;
    }
    
    for (int i = 0; i < 4; i++)
    {
        int nx = cur_x + dx[i];
        int ny = cur_y + dy[i];
        int cur_cost = cur_value + line_cost;
        if (nx < 0 || nx >= board_size || ny < 0 || ny >= board_size || board[nx][ny] == 1) continue;
        if (direction != 2 && direction != i/2) cur_cost += corner_cost;
        if (cost[nx][ny][i] < cur_cost ) continue;
        cost[nx][ny][i] = cur_cost;
        dfs(board, board_size, nx, ny, cur_cost, i / 2); 
    }
}

int solution(vector<vector<int>> board) {
    int n = board.size();
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            for (int k = 0; k < 4; ++k)
                cost[i][j][k] = 0x3f3f3f3f;
    
    dfs(board, board.size(), 0, 0, 0, 2);
    
    return answer;
}