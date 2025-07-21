#include <functional>
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

using namespace std;

int board[52][52];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int answer = 0x3f3f3f3f;
    int n, m;
    cin >> n >> m;

    // x, y 좌표, 각각의 집들과 치킨 집들과의 거리 (인덱스, 거리)
    vector<tuple<int, int, vector<int>>> chicken;
    vector<pair<int, int>> house;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 1) house.push_back({ i, j });
            else if (board[i][j] == 2) chicken.push_back({ i, j , {} });
        }
    }

    for (int i = 0; i < chicken.size(); i++)
    {
        for (int j = 0; j < house.size(); j++)
        {
            int x = abs(get<0>(chicken[i]) - house[j].first);
            int y = abs(get<1>(chicken[i]) - house[j].second);
            get<2>(chicken[i]).push_back({ x + y });
        }
    }

    vector<int> com(chicken.size(), 0);
    fill(com.begin(), com.begin() + m, 1);

    do
    {
        vector<int> tmp(house.size(), 0x3f3f3f3f);
        for (int i = 0; i < com.size(); i++)
        {
            if (com[i] == 1)
            {
                for (int j = 0; j < get<2>(chicken[i]).size(); j++)
                {
                    tmp[j] = min(tmp[j], get<2>(chicken[i])[j]);
                }                    
            }
        }

        int temp = 0;
        for (auto c: tmp)
            temp += c;

        answer = min(answer, temp);
    }
    while (prev_permutation(com.begin(), com.end()));

    cout << answer << "\n";
    return 0;
}