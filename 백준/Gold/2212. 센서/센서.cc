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

    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    sort(v.begin(), v.end());

    vector<int> len;
    for (int i = 1; i < n; i++)
        len.push_back(v[i] - v[i - 1]);
    sort(len.begin(), len.end(), greater<int>());

    int sum = 0;
    for (int i = k - 1; i < n - 1; i++)
        sum += len[i];

    cout << sum;
    return 0;
} 