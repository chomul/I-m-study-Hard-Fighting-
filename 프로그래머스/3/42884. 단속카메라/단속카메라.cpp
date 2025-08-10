#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <map>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 1;

    sort(routes.begin(), routes.end(), [](const vector<int>& a, const vector<int>& b)
    {
        return a[1] < b[1];
    });
    
    int camera_pos = routes[0][1]; 
    
    for (int i = 1; i < routes.size(); i++)
    {
        if (routes[i][0] > camera_pos)
        {
            answer++;
            camera_pos = routes[i][1]; 
        }
    }
    return answer;
}