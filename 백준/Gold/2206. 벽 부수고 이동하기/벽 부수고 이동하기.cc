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

#define SIZE 1002

int board[SIZE][SIZE];
bool visited[SIZE][SIZE][2];  // visited[x][y][broken]  
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    // 입력 받기 (1-indexed)
    for(int i = 1; i <= n; i++)
    {
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
        auto cur = q.front();
        int x = get<0>(cur);
        int y = get<1>(cur);       
        int broken = get<2>(cur);      
        int dist = get<3>(cur);
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

            int nb = broken + board[nx][ny];         // 다음 이동시 벽 파괴 유무 카운팅
            if(nb > 1) continue;                     // k초과 벽 파괴 불가
            if(visited[nx][ny][nb]) continue;        // 이미 같은 상태 방문 (벽 파괴 수가 같을 경우 이미 방문)

            visited[nx][ny][nb] = true;
            q.emplace(nx, ny, nb, dist + 1);
        }
    }

    // 도달 불가능
    cout << -1;
    return 0;
}