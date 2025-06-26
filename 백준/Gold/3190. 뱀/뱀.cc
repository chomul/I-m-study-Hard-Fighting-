#include <iostream>
#include <queue>
#include <stack>
#include <string>
using namespace std;

bool compare(queue<pair<int, int>> q, int xvalue, int yvalue)
{
    while (!q.empty())
    {
        if (q.front().first == xvalue && q.front().second == yvalue)
            return true;    // 내 몸통에 머리를 박음

        q.pop();
    }
    return false;
}

int main(int argc, char* argv[])
{
    int n, k, l;
    cin >> n >> k;
    vector<pair<int, int>> apple_arr;
    vector<pair<int, char>> arrow_arr;
    queue<pair<int, int>> snake;
    for (int i = 0; i < k; i++)
    {
        int a, b;
        cin >> a >> b;

        apple_arr.emplace_back(a, b);
    }
    
    int time = 0;   // time 은 시간     
    int up = 0;      
    int right = 1;
    int cnt = 0; // 방향을 바꾸기 위한 인덱스
    snake.emplace(1,1);

    cin >> l;
    for (int i = 0; i < l; i++)
    {
        int c;
        char d;
        cin >> c >> d;
        arrow_arr.emplace_back(c, d);
    }

    while (true)
    {
        // x 초 동안 움직이는 코드
        // 앞 뒤로 늘어났다 줄었다 하기 때문에 큐를 사용하는 것이 용이
        time++;

        // 1. 몸 길이 늘려 머리를 다음칸에 위치
        int next_up = snake.back().first + up;
        int next_right = snake.back().second + right;

        // 2. 벽이나 자기자신의 몸과 부딪히면 게임이 끝
        if (next_up <= 0 || next_right <= 0 || next_up > n || next_right > n || compare(snake, next_up, next_right))
        {
            cout << time;
            return 0;
        }
        else
        {
            snake.emplace(next_up, next_right);
        }
            
        // 3. 이동한 칸에 사과가 있다면, 그 칸에 있던 사과가 없어지고 꼬리는 움직이지 않는다.
        bool chkapple = false;

        for (auto& apple : apple_arr)
            if (apple.first == next_up && apple.second == next_right)  // 사과가 있다면 제거 X
            {
                apple.first = -1;
                apple.second = -1;
                chkapple = true;
                break;
            }
            
        // 4. 이동한 칸에 사과가 없다면, 몸길이를 줄여서 꼬리가 위치한 칸을 비워준다
        if (!chkapple)
            snake.pop();

        // 방향 조정 코드 (회전 변환 행렬 코드 이용)
        // Left : (a, b) -> (-b, a)
        // Right : (a, b) -> (b, -a)
        if (cnt < arrow_arr.size() && arrow_arr[cnt].first == time)
        {
            if (arrow_arr[cnt].second == 'L')
            {
                int tmep = up;
                up = -right;
                right = tmep;
            }
            else if (arrow_arr[cnt].second == 'D')
            {
                int tmep = up;
                up = right;
                right = -tmep;
            }
            cnt++;
        }       
    }
    
    cout << time;
    
    return 0;
}
