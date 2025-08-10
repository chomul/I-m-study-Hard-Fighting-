#include <string>
#include <vector>

using namespace std;

char max_string(string str, int& start, int& end)
{
    char max_char = str[start];
    int max_index = start;
    for (int i = end; i >= start; i--)
    {
        if (str[i] >= max_char)
        {
            max_char = str[i];
            max_index = i + 1;            
        }
    }
    start = max_index;
    end++;
    return max_char;
}

string solution(string number, int k) {
    string answer = "";

    int start = 0;
    int end = k;
    while (end < number.size())
    {
        answer += max_string(number, start, end);
    }     
    return answer;
}
