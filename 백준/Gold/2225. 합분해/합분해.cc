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

    int n, k;
    cin >> n >> k;
    n++;
    
    vector<vector<long long>> v(k, vector<long long>());
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 || j == 0) v[i].push_back(1);
            else v[i].push_back((v[i - 1][j] + v[i][j - 1]) % 1000000000);
        }
    }

    cout << v[k - 1][n - 1] % 1000000000;
    return 0;
} 