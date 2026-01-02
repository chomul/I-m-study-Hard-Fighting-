#include <algorithm>
#include <iostream>
#include <vector>
#include <limits.h>
#include <queue>
#include <stack>
#include <tuple>
#include <utility>
#include <cmath>

using namespace std;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n;
    vector<pair<int, int>> crain(n);
    for (int i = 0; i < n; i++)
        cin >> crain[i].first;
    
    sort(crain.begin(), crain.end(), [](pair<int, int> a, pair<int, int> b)
    {
        return a.first < b.first;
    });
    
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        int temp;
        cin >> temp;
        for (int j = 0; j < n; j++)
        {
            if (crain[j].first >= temp)
            {
                crain[j].second++;
                break;
            }
        }
    }
    
    int cnt = 0;
    for (int i = 0; i < n; i++)
        cnt += crain[i].second;
    if (cnt != m)
    {
        cout << -1 << endl;
        return 0;
    }    
    
    int sum = m;
    int max_cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int temp = ceil(static_cast<float>(sum) / (crain.size() - i));
        max_cnt = max(max_cnt, temp);
        sum -= crain[i].second;
    }
    
    cout << max_cnt << endl;
}