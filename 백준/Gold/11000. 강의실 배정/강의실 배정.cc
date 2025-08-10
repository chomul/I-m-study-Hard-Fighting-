#include <algorithm>
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


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i].first >> v[i].second;

    sort(v.begin(), v.end());
    
    priority_queue<int, vector<int>, greater<int>> room;
    room.push(v[0].second);
    for (int i = 1; i < n; i++)
    {
        if (room.top() <= v[i].first)
        {
            room.pop();
            room.push(v[i].second);
        }
        else room.push(v[i].second);
    }
    cout << room.size();
    return 0;
} 