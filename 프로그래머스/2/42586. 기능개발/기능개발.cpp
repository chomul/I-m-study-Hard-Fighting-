#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) 
{
    vector<int> answer;

    queue<int> days;

    for (int i = 0; i < progresses.size(); i++)
    {
        if ((100 - progresses[i]) % speeds[i] != 0)
            days.push(((100 - progresses[i]) / speeds[i]) + 1);
        else
            days.push((100-progresses[i]) / speeds[i]);
    }

    int cnt = 0;    // 배포 수
    int temp = 0;   // 현재 진행중인 가장 앞 작업
    while (!days.empty())
    {
        if (temp == 0)
        {
            temp = days.front();
            cnt++;
            days.pop();
        }
        else if (temp >= days.front())
        {
            cnt++;
            days.pop();
        }
        else
        {
            answer.push_back(cnt);
            cnt = 0;
            temp = days.front();
            cnt++;
            days.pop();
        }
    }
    answer.push_back(cnt);
    return answer;
}