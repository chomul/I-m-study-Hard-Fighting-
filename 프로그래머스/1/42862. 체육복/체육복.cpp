#include <string>
#include <vector>

using namespace std;

int student[31];
int solution(int n, vector<int> lost, vector<int> reserve)
{
    int answer = 0;
    for (int i = 0; i < n; i++)
        student[i] = 1;
    for (int i = 0; i < lost.size(); i++)
        student[lost[i] - 1]--;
    for (int i = 0; i < reserve.size(); i++)
        student[reserve[i] - 1]++;

    for (int i = 0; i < n; i++)
    {
        if (student[i] == 0)
        {
            int left = i - 1;
            int right = i + 1;
            if (left >= 0 && student[left] >= 2)
            {
                student[left]--;
                student[i]++;
            }
            else if (right < n && student[right] >= 2)
            {
                student[right]--;
                student[i]++;
            }
        }
    }

    for (int i = 0; i < n; i++)
        if (student[i] >= 1)
            answer++;
    
    return answer;
}