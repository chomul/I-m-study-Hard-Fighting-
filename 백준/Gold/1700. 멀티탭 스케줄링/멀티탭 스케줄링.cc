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

    int n, m;
    cin >> n >> m;

    map<int, queue<int>> map;
    vector<int> order;
    for (int i = 0; i < m; i++)
    {
        int temp;
        cin >> temp;
        map[temp].push(i);
        order.push_back(temp);
    }

    unordered_set<int> plug;
    int count = 0;
    for (int i = 0; i < order.size(); i++)
    {   // 플러그인 여유 자리가 있을 경우
        map[order[i]].pop();
        if (plug.size() != n)
        {
            plug.insert(order[i]);            
        }
        else // 플러그인이 꽉찬 경우
        {   // 플러그인 뽑아야 하는 경우
            if (plug.count(order[i]) == 0)
            {
                int max = 0; // 가장 나중에 꺼네는것 혹은 안사용하는것
                int max_index = 0;
                for (auto it : plug)
                {
                    if (map[it].empty()) // 재사용 안하는것
                    {
                        max = it;
                        break;
                    }
                    else
                    {
                        if (max_index < map[it].front() - i)
                        {
                            max = it;
                            max_index = map[it].front() - i;
                        }
                    }
                }
                plug.erase(max);
                plug.insert(order[i]);
                
                count++;
            }
        }
    }
    cout << count;
    return 0;
} 