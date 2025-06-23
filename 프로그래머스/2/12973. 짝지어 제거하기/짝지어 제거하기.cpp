#include <iostream>
#include <string>
#include <stack>
using namespace std;

int solution(string s)
{
    stack<char> st;

    for (auto c : s)
    {
        if (st.empty()) st.push(c);
        else if (st.top() == c) st.pop();
        else st.push(c);
    }


    return st.empty();
}