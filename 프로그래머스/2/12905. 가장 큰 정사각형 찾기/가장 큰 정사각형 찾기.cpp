#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> board)
{
    int max_len = 0;
    
    for (int i = 0; i < board.size(); i++)
    {
        if (board[i][0] == 1)
        {
            max_len = 1;
            break;
        }
    }

    if (max_len == 0)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            if (board[0][j] == 1)
            {
                max_len = 1;
                break;
            }
        }
    }

    for (int i = 1; i < board.size(); i++)
    {
        for (int j = 1; j < board[0].size(); j++)
        {
            // 현재 위치(i, j)가 1인 경우에만 정사각형 길이 증가 가능
            if (board[i][j] == 1)
            {
                board[i][j] = min({board[i - 1][j], board[i][j - 1], board[i - 1][j - 1]}) + 1;
                max_len = max(max_len, board[i][j]);
            }
        }
    }

    return max_len * max_len;
}