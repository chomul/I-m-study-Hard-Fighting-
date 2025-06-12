#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    answer.assign(arr1.size(), vector<int>(arr2[1].size(), 0));
    
    for(int i = 0; i < arr1.size(); i++)
    {
        for(int j = 0; j < arr1[i].size(); j++)
        {
            for(int g = 0; g < arr2[j].size(); g++)
            {
                answer[i][g] += arr1[i][j]*arr2[j][g];
            }
        }
    }
    
    
    return answer;
}