#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <tuple>
#include <vector>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

// 브루트 포스 문제 -> 일일히 모든 경우의 수 계산
int board[9][9];
int vis[9][9];
// x, y, camera_num
vector<tuple<int,int,int>> camera;

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int n, m;
int answer = 0x3f3f3f3f;

void check(int x, int y, int dir, bool flag = true){
    dir %= 4; 
    while(1){
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        x = nx;
        y = ny;
        if(nx < 0 || ny < 0 || nx >= n || ny >= m) return;
        if(board[nx][ny] == 6) return;
        if(board[nx][ny] >= 1 && board[nx][ny] <= 5) continue;
        if(flag) vis[nx][ny]--; // +로 할경우 6과 겹쳐버리는 문제가 생길 수 도 있음
        else vis[nx][ny]++;
    }
}

void Fcamera(int depth,int cur_camera_num, int dir, bool flag)
{
    if (cur_camera_num == 1)
    {
        check(get<0>(camera[depth]), get<1>(camera[depth]), dir, flag);
    }
    else if (cur_camera_num == 2)
    {
        check(get<0>(camera[depth]), get<1>(camera[depth]), dir, flag);
        check(get<0>(camera[depth]), get<1>(camera[depth]), dir + 2, flag);
    }
    else if (cur_camera_num == 3)
    {
        check(get<0>(camera[depth]), get<1>(camera[depth]), dir, flag);
        check(get<0>(camera[depth]), get<1>(camera[depth]), dir + 1, flag);
    }
    else if (cur_camera_num == 4)
    {
        check(get<0>(camera[depth]), get<1>(camera[depth]), dir, flag);
        check(get<0>(camera[depth]), get<1>(camera[depth]), dir + 1, flag);
        check(get<0>(camera[depth]), get<1>(camera[depth]), dir + 2, flag);
    }
    else if (cur_camera_num == 5)
    {
        check(get<0>(camera[depth]), get<1>(camera[depth]), dir, flag);
        check(get<0>(camera[depth]), get<1>(camera[depth]), dir + 1,flag);
        check(get<0>(camera[depth]), get<1>(camera[depth]), dir + 2,flag);
        check(get<0>(camera[depth]), get<1>(camera[depth]), dir + 3,flag);
    }
}

void dfs(int depth)
{
    if (depth == camera.size())
    {
        int temp = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (vis[i][j] == 0) temp++;
        answer = min(answer, temp);
        return;
    }

    int cur_camera_num = get<2>(camera[depth]);

    for (int dir = 0; dir < 4; dir++)
    {
        Fcamera(depth, cur_camera_num, dir, true);
      
        dfs(depth + 1);

        Fcamera(depth, cur_camera_num, dir, false);
    }

    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int temp;
            cin >> temp;
            board[i][j] = temp;
            vis[i][j] = temp;
            if (temp >= 1 && temp <= 5)
            {
                camera.push_back(make_tuple(i, j, temp));
            }
        }
    }

    dfs(0);

    cout << answer;
    
    return 0;
}