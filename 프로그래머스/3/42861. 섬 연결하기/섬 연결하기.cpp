#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int parent[101];

int find(int x)
{
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

bool union_set(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x == y) return false;
    parent[x] = y;
    return true;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    vector<vector<int>> temp_costs = costs;
    sort(temp_costs.begin(), temp_costs.end(), [](const vector<int>& a, const vector<int>& b)
    {
        return a[2] < b[2];
    });

    for (int i = 0; i < n; i++)
        parent[i] = i;

    for (auto cost : temp_costs)
    {
        if (union_set(cost[0], cost[1]))
            answer += cost[2];
    }
    
    return answer;
}