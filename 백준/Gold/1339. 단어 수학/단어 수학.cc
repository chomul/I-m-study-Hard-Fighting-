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

    map<char, int> spell;
    vector<string> spells;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        spells.push_back(s);

        int decimal = 1;
        for (int j = s.length() - 1; j >= 0; j--)
        {
            spell[s[j]] += decimal;
            decimal *= 10;
        }
    }

    vector<pair<char, int>> v(spell.begin(), spell.end());
    sort(v.begin(), v.end(), [](pair<char, int> a, pair<char, int> b) { return a.second > b.second; });
    for (int i = 0; i < v.size(); i++)
        spell[v[i].first] = 10 - (i + 1);

    int sum = 0;
    for (auto s : spells)
    {
        string temp;
        for (auto c : s)
            temp += to_string(spell[c]);
        sum += stoi(temp);
    }

    cout << sum;
    
    return 0;
} 