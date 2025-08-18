#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;

    int sum, time = 0;
    queue<pair<int, int>> q;
    time++;
    q.push({truck_weights[0], time});
    sum = truck_weights[0];
    
    for (int i = 1; i < truck_weights.size(); i++)
    {
        while (!q.empty())
        {
            time++;
            if (time - q.front().second >= bridge_length)
            {
                sum -= q.front().first;
                q.pop();
            }
            
            if (sum + truck_weights[i] <= weight)
            {
                sum += truck_weights[i];
                q.push({truck_weights[i], time} );
                break;
            }
        }
    }

    if (!q.empty())
        answer = time + bridge_length;
    
    return answer;
}