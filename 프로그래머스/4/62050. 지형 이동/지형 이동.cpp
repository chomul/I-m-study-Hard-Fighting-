#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

struct Node
{
    int x, y;
    int value = -1;

    Node(int x, int y, int value) : x(x), y(y), value(value) {}
};

bool isladder(Node* a, Node* b, int height)
{
    return abs(a->value - b->value) > height;
}

int parent[90002];
int dx[4] = { -1, 0, 1, 0};
int dy[4] = { 0, 1, 0, -1};

int find(int x)
{
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

bool union_set(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x == y) return false;
    parent[y] = x;
    return true;
}
int solution(vector<vector<int>> land, int height)
{
    int answer = 0;
    int n = static_cast<int>(land.size());
    unordered_map<int, Node*> nodes;
    vector<tuple<int,int,int>> min_ladder;
    for (int i = 1; i <= n * n; i++)
        parent[i] = i;


    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            nodes.insert({j + 1 + i * n, new Node(j + 1, i + 1, land[i][j])});

    for (auto c : nodes)
    {
        for (int k = 0; k < 4; k++)
        {
            if (c.second->x + dx[k] > 0 && c.second->x + dx[k] <= n && c.second->y + dy[k] > 0 && c.second->y + dy[k] <= n)
            {
                if (!isladder(c.second, nodes[c.second->x + dx[k] + (c.second->y + dy[k] - 1) * n], height))
                    union_set(c.first, c.second->x + dx[k] + (c.second->y + dy[k] - 1) * n);
            }
        }
    }

    for (auto c : nodes)
    {
        for (int k = 0; k < 4; k++)
        {
            if (c.second->x + dx[k] > 0 && c.second->x + dx[k] <= n && c.second->y + dy[k] > 0 && c.second->y + dy[k] <= n)
            {
                int a = find(c.first);
                int b = find(c.second->x + dx[k] + (c.second->y + dy[k] - 1) * n);
                if (a != b)
                    min_ladder.push_back({a, b, abs(c.second->value - nodes[c.second->x + dx[k] + (c.second->y + dy[k] - 1) * n]->value)});
            }
        }
    }

    sort(min_ladder.begin(), min_ladder.end(), [](tuple<int, int, int> a, tuple<int, int, int> b)
    {
        return get<2>(a) < get<2>(b);
    });

    for (int i = 1; i <= n * n; i++)
        parent[i] = i;

    for (auto c : min_ladder)
    {
        if (union_set(get<0>(c), get<1>(c)))
            answer += get<2>(c);
    }
 
    return answer;
}