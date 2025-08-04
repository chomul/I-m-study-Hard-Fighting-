#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> money) {
    vector<int> com_start(money.size(), 0);
    vector<int> not_start(money.size(), 0);

    com_start[0] = money[0];
    not_start[0] = 0;
    com_start[1] = money[0];
    not_start[1] = money[1];

    for (int i = 2; i < money.size() - 1; i++)
    {
        com_start[i] = max(com_start[i - 1], money[i] + com_start[i - 2]);        
    }

    for (int i = 2; i < money.size(); i++)
    {
        not_start[i] = max(not_start[i - 1], not_start[i - 2] + money[i]);
    }

    return max(com_start[money.size() - 2], not_start[money.size() - 1]);
}