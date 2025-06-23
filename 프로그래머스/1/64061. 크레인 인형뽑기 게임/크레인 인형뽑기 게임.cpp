#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    stack<int> basket;
    int answer = 0;
    for (int c : moves)
    {
        for (int i = 0; i < board.size(); i++)
        {
            if (board[i][c - 1] != 0)
            {
                if (basket.empty() || basket.top() != board[i][c - 1])
                {
                    basket.push(board[i][c - 1]);
                }
                else if (basket.top() == board[i][c - 1])
                {
                    basket.pop();
                    answer += 2;
                }
                board[i][c - 1] = 0;
                break;
            }
        }        
    }

    return answer;
}