#include <iostream>
#include <queue>
#include <string>
#include <tuple>
using namespace std;

#define SIZE 1002

int board[SIZE][SIZE];
bool visited[SIZE][SIZE][11];  // visited[x][y][broken]  
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;
    // 입력 받기 (1-indexed)
    for(int i = 1; i <= n; i++){
        string s;
        cin >> s;
        for(int j = 1; j <= m; j++){
            board[i][j] = s[j-1] - '0';
        }
    }

    // BFS 큐: (x, y, 부순_벽_개수, 현재_거리)
    queue<tuple<int,int,int,int>> q;
    visited[1][1][0] = true;
    q.emplace(1, 1, 0, 1);

    while(!q.empty()){
        auto [x, y, broken, dist] = q.front();
        q.pop();

        // 도착
        if(x == n && y == m){
            cout << dist;
            return 0;
        }

        for(int dir = 0; dir < 4; dir++){
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(nx < 1 || nx > n || ny < 1 || ny > m) continue;

            int nb = broken + board[nx][ny];
            if(nb > k) continue;                     // k초과 벽 파괴 불가
            if(visited[nx][ny][nb]) continue;        // 이미 같은 상태 방문

            visited[nx][ny][nb] = true;
            q.emplace(nx, ny, nb, dist + 1);
        }
    }

    // 도달 불가능
    cout << -1;
    return 0;
}
