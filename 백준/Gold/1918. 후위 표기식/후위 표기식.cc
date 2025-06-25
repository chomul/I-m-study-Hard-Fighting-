#include <iostream>
#include <stack>
#include <string>
using namespace std;

int priority(char op) {
    if (op == '(') return 0;
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return -1;
}

int main(int argc, char* argv[])
{   // 후위
    string s = "";
    cin >> s;
    string answer = "";
    stack<char> st;
    
    for (char c : s) 
    {
	    if (isalpha(c)) answer += c;
	    else if (c == '(') st.push(c);
	    else if (c == ')') {
	        while (!st.empty() && st.top() != '(') {
	            answer += st.top(); 
	            st.pop();
	        }
	        st.pop(); // '(' 제거
	    }
	    else {
	        while (!st.empty() && priority(st.top()) >= priority(c)) {
	            answer += st.top(); 
	            st.pop();
	        }
	        st.push(c);
	    }
		}
		while (!st.empty()) {
		    answer += st.top();
		    st.pop();
		}
    cout << answer << endl;
    
    return 0;
}
