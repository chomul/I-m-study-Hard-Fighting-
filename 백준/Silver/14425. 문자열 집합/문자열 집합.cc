#include <bits/stdc++.h>
#include "unordered_set"
using namespace std;

int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, cnt = 0;
    cin >> n >> m;

    unordered_set<string> se;
    while (n--)
    {
        string s;
        cin >> s;
        se.insert(s);
    }

    while (m--)
    {
        string s;
        cin >> s;
        if (se.find(s) != se.end())
            cnt++;
    }
    cout << cnt;
}