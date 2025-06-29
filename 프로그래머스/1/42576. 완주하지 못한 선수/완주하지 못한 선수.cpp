#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";

    unordered_multiset<string> data;
    for(string part : participant)
        data.insert(part);
    
    for(string com : completion)
        data.erase(data.find(com));
        
    for(string re : data)
        return re;
    
    return answer;
}