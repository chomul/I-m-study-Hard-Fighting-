#include <iostream>
#include <map>
#include <queue>
#include <tuple>
#include <vector>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int n, m;
vector<vector<int>> adj; 
vector<int> match;       // 매칭된 직원 번호
vector<bool> visited;

bool dfs(int employee)
{
    if (visited[employee])
    {
        return false;
    }
    visited[employee] = true;
    
    for (int work : adj[employee])
    {
        // work가 아직 매칭 X
        // work에 이미 매칭된 직원이 다른 일로 옮겨갈 수 있다면
        if (match[work] == -1 || dfs(match[work]))
        {
            match[work] = employee;
            return true;
        }
    }
    return false; 
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    adj.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int work_cnt;
        cin >> work_cnt;
        for (int j = 0; j < work_cnt; j++)
        {
            int work_num;
            cin >> work_num;
            adj[i].push_back(work_num);
        }
    }

    match.assign(m + 1, -1); 
    int total_matches = 0;
    
    for (int i = 1; i <= n; i++)
    {
        visited.assign(n + 1, false);
        if (dfs(i))
            total_matches++;
    }

    cout << total_matches;
    
    return 0;
} 