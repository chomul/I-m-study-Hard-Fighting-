#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string s) {
    int answer = 0;

    stack<int> sum;
    string temp = "";
    for (auto c : s)
    {
        if (c != ' ')
            temp += c;
        else
        {
            if (temp == "Z")
                sum.pop();
            else
                sum.push(stoi(temp));

            temp = "";
        }
    }

    if (temp == "Z")
        sum.pop();
    else
        sum.push(stoi(temp));

    while (!sum.empty())
    {
        answer += sum.top();
        sum.pop();
    }

    return answer;
}