#include <string>
#include <vector>
#include <unordered_set>
#include <iostream>
using namespace std;

#define SIZE 202

int parent[SIZE];

int find(int x)
{
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}

void union_set(int x, int y)
{
    int a = find(x);
    int b = find(y);
    if (a == b) return;
    parent[a] = b;
    return;
}


int solution(int n, vector<vector<int>> computers)
{
    for (int i = 0 ; i < n ; i++)
        parent[i] = i;

    for (int i = 0 ; i < computers.size() ; i++)
    {
        for (int j = 0 ; j < computers[i].size() ; j++)
        {
            if (i == j) continue;
            if (computers[i][j] == 0) continue;
            union_set(i, j);
        }
    }
    
    for (int i = 0 ; i < n ; i++)
        cout << parent[i];

    unordered_set<int> set;
    for (int i = 1 ; i <= n ; i++)
        set.insert(find(i));
    
    return set.size();
}
