#include <bits/stdc++.h>
#include "unordered_set"
using namespace std;

int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<pair<int, string>> vec(n);

    for (int i = 0; i < n; i++)
        cin >> vec[i].first >> vec[i].second;

    stable_sort(vec.begin(), vec.end(), [](pair<int, string> a, pair<int, string> b) {return a.first < b.first; });

    for (auto c : vec)
        cout << c.first << ' ' << c.second << '\n';

}