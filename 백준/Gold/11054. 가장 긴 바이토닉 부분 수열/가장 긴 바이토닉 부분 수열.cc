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

    vector<int> vec(n);
    for (int i = 0; i < n; i++)
        cin >> vec[i];

    vector<int> dp_left(n, 0);
    vector<int> dp_right(n, 0);

    dp_left[0] = 1;
    dp_right[n - 1] = 1;
    
    for (int i = 0; i < n; i++)
    {
        int max_left = 0;
        for (int j = 0; j < i; j++)
        {
            if (vec[j] < vec[i])
                max_left = max(max_left, dp_left[j]);
        }
        dp_left[i] = max_left + 1;
    }

    for (int i = n - 1; i >= 0; i--)
    {
        int max_right = 0;
        for (int j = i + 1; j < n; j++)
        {
            if (vec[j] < vec[i])
                max_right = max(max_right, dp_right[j]);
        }
        dp_right[i] = max_right + 1;
    }

    int max_ans = 0;
    for (int i = 0; i < n; i++)
        max_ans = max(max_ans, dp_left[i] + dp_right[i] - 1);
    
    cout << max_ans << endl;

    return 0;
} 