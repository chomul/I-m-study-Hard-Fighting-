#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    for (auto c: commands)
    {
        int start = c[0] - 1;
        int end = c[1] - 1;
        int value = c[2] - 1;
        vector<int> temp;
        for (int i = start; i <= end; i++)
            temp.push_back(array[i]);

        sort(temp.begin(), temp.end());
        answer.push_back(temp[value]);
    }
    return answer;
}