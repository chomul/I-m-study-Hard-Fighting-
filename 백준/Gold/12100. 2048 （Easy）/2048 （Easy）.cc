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

int n;
int answer = 0;

void rotate(vector<vector<int>>& board)
{
    vector<vector<int>> temp(n, vector<int>(n));
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++) 
            temp[i][j] = board[n - 1 - j][i];

    board = temp;
}

void move(vector<vector<int>>& board)
{
    for (int i = 0; i < n; i++) {
        queue<int> q;
        // 0이 아닌 블록을 순서대로 큐에 넣음
        for (int j = 0; j < n; j++) 
            if (board[i][j] != 0) q.push(board[i][j]);

        // 현재 행을 0으로 초기화
        fill(board[i].begin(), board[i].end(), 0);

        int idx = 0;
        while (!q.empty())
        {
            int data = q.front();
            q.pop();

            if (board[i][idx] == 0)  // 현재 위치가 비어있으면 블록을 놓음
                board[i][idx] = data;
            else if (board[i][idx] == data)
            {   // 같은 값이면 합침
                board[i][idx] *= 2;
                idx++; // 다음 위치로 이동
            }
            else
            { // 다른 값이면 바로 옆에 놓음
                idx++;
                board[i][idx] = data;
            }
        }
    }
}

void sol(int depth, vector<vector<int>> board)
{
    // 5번 이동했을 때 최댓값 탐색
    if (depth == 5)
    {
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < n; j++) 
                answer = max(answer, board[i][j]);
        return;
    }

    // 네 방향으로 이동 시도
    for (int i = 0; i < 4; i++)
    {
        vector<vector<int>> next_board = board;
        
        // i번 회전 (0: 왼쪽, 1: 위, 2: 오른쪽, 3: 아래)
        for (int j = 0; j < i; j++) 
            rotate(next_board);
        
        move(next_board);

        // 원래 방향으로 되돌리기 위해 회전
        // (4 - i) % 4 번 회전하면 원래 상태로 돌아감
        for (int j = 0; j < (4 - i) % 4; j++) 
            rotate(next_board);

        sol(depth + 1, next_board);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    vector<vector<int>> initial_board(n, vector<int>(n));
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++) 
            cin >> initial_board[i][j];

    sol(0, initial_board);

    cout << answer << endl;
    return 0;
}