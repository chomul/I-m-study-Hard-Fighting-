#include <string>
#include <vector>
#include <stack>

using namespace std;
struct Node
{
    Node* next;
    Node* prev;
    int data;
};

string solution(int n, int k, vector<string> cmd) {
    string answer;
    stack<int> deleted;
    
    vector<Node*> node(n);
    for(int i = 0; i < n; i++){
        node[i] = new Node();   
        node[i]->data = i;
    }
    
    Node* curr = node[k];
    vector<bool> remained(n, true);
    
    for(int i = 0; i < n; i++){
        if(i > 0){
            node[i]->prev = node[i - 1];
        }
        if(i < n - 1){
            node[i]->next = node[i + 1];    
        }
    }

    for (const string& c : cmd) {
        if (c[0] == 'U') {
            int move = stoi(c.substr(2));
            while(move-- > 0) curr = curr->prev;            
        } else if (c[0] == 'D') {
            int move = stoi(c.substr(2));
            while(move-- > 0) curr = curr->next;      
        } else if (c[0] == 'C') {
            deleted.push(curr->data);
            remained[curr->data] = false;

            if (curr->prev) curr->prev->next = curr->next;
            if (curr->next) curr->next->prev = curr->prev;

            if (curr->next) curr = curr->next;
            else curr = curr->prev;
        } else if (c[0] == 'Z') {
            int index = deleted.top();
            remained[deleted.top()] = true;
            deleted.pop();

            if (node[index]->prev) node[index]->prev->next = node[index];
            if (node[index]->next) node[index]->next->prev = node[index];
        }
    }

    for (auto remide : remained)
        answer += remide ? 'O': 'X';
    
    return answer;
}