#include <bits/stdc++.h>
#include "unordered_set"
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b)
{
    if (a.second != b.second)
        return a.second < b.second;
    else
        return a.first < b.first;
}

int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<pair<int, int>> vec(n);

    for (int i = 0; i < n; i++)
        cin >> vec[i].first >> vec[i].second;

    sort(vec.begin(), vec.end(), compare);

    for (auto c : vec)
        cout << c.first << ' ' << c.second << '\n';

}