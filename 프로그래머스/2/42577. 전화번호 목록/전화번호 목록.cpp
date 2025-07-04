#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

bool solution(vector<string> phone_book) 
{
  unordered_set<string> phone_set;

    // 모든 번호를 set에 저장
    for (const string& number : phone_book) {
        phone_set.insert(number);
    }

    // 각 번호마다 접두어가 있는지 확인
    for (const string& number : phone_book) {
        string prefix = "";
        for (int i = 0; i < number.size() - 1; ++i) {
            prefix += number[i];
            if (phone_set.find(prefix) != phone_set.end()) {
                return false;
            }
        }
    }
    

    return true;
}