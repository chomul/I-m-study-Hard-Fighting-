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

// 1. 가로, 세로, 작은 판 에서 0이 하나인 곳을 먼저 채움
// 2. 나머지는 경우의 수로 모든 경우의 수를 따짐

int board[9][9];
// 각 행, 열, 3x3 박스에 특정 숫자가 사용되었는지 확인하는 배열
bool row_check[9][10];
bool col_check[9][10];
bool mini_check[9][10];

int get_mini_idx(int x, int y)
{
    return (x / 3) * 3 + (y / 3);
}

void dfs(int x, int y)
{
    if (x == 9)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
                cout << board[i][j] << " ";
            cout << endl;
        }
        exit(0);       
    }

    if (board[x][y] != 0)
    {
        if (y < 8) dfs(x, y + 1);
        else dfs(x + 1, 0);
        return;
    }

    int mini_idx = get_mini_idx(x, y);
    for (int num = 1; num <= 9; num++)
    {
        if (!row_check[x][num] && !col_check[y][num] && !mini_check[mini_idx][num])
        {
            row_check[x][num] = true;
            col_check[y][num] = true;
            mini_check[mini_idx][num] = true;
            board[x][y] = num;            
            if (y < 8) dfs(x, y + 1);
            else dfs(x + 1, 0);
            board[x][y] = 0;
            row_check[x][num] = false;
            col_check[y][num] = false;
            mini_check[mini_idx][num] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> board[i][j];
            if (board[i][j] != 0)
            {
                row_check[i][board[i][j]] = true;
                col_check[j][board[i][j]] = true;
                mini_check[get_mini_idx(i, j)][board[i][j]] = true;           
            }
       }   
    }
    
    dfs(0, 0);

    return 0;
}