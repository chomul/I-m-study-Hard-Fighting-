#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    stack<int> st;
    for (auto c : arr)
    {
        if (st.empty() || st.top() != c)
            st.push(c);
    }

    while (!st.empty())
    {
        answer.push_back(st.top());
        st.pop();
    } 
    reverse(answer.begin(), answer.end());

return answer;
}