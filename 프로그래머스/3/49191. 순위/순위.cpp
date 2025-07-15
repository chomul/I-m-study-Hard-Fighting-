#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int board[101][101];
int INF = 0x3f3f3f3f;
using namespace std;

int solution(int n, vector<vector<int>> results)
{
    int answer = 0;
    
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i != j) board[i][j] = INF;
    
    for (int i = 0; i < results.size(); i++)
        board[results[i][0]][results[i][1]] = 1;
    
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)         
            for (int j = 1; j <= n; j++)             
                board[i][j] = min(board[i][j], board[i][k] + board[k][j]);


    unordered_map<int, int> cnt_min;
    unordered_map<int, int> cnt_max;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (board[j][i] < INF && board[j][i] != 0)
            {
                cnt_max[j]++;
                cnt_min[i]++;
            }
        }
    }
    
    for (int i = 1; i <= n; i++)
        if (n - 1 == cnt_max[i] + cnt_min[i])
            answer++;    
    return answer;
}
