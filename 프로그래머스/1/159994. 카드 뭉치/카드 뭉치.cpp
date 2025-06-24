#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
int Lindex = 0;
int Rindex = 0;

for (auto c : goal)
{
    if (Lindex < cards1.size() && cards1[Lindex] == c) Lindex++;
    else if (Rindex < cards2.size() && cards2[Rindex] == c) Rindex++;
    else return "No";
}

return (goal.size() == Lindex + Rindex) ? "Yes" : "No";
}