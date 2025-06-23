#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string s) {
    int answer = 0;
    
  
    for (int i = 0; i < s.length(); ++i) 
    {
        string temp = s.substr(i) + s.substr(0, i);
        
        
    stack<char> st;    
    for(auto c : temp)
    {
        if(c == '(') st.push('(');
        else if(c == '[') st.push('[');
        else if(c == '{') st.push('{');
        else if(c == ')') 
        {
            if(!st.empty() && st.top() == '(') st.pop();
            else st.push(')');
        }
        else if(c == ']')
        {
            if(!st.empty() && st.top() == '[') st.pop();
            else st.push(']');
        }
        else if(c == '}')
        {
            if(!st.empty() && st.top() == '{') st.pop();
            else st.push('}');
        }
    }

    answer += st.empty();
    }      

    
    return answer;
}