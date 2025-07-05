#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int parent[200001];
int size_set[200001];

int find(int x)
{
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);    
}

bool union_sets(int x, int y)
{
    x = find(x);
    y = find(y);

    // 같은 그룹이기 때문에 Union 진행 X
    if (x == y) return false;
    else
    {
        parent[y] = x;
        size_set[x] += size_set[y];
        return true;       
    }
}



int main(int argc, char* argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    while (n--)
    {
        int f;
        cin >> f;

        for (int i = 0; i < 200001; i++)
        {   // 값 초기화
            parent[i] = 0;
            size_set[i] = 0;       
        }

        unordered_map<string, int> map;
        string a, b;
        int set_index = 1;

        for (int i = 0; i < f; i++)
        {
            cin >> a >> b;

            if (map.find(a) == map.end())
            {
                map[a] = set_index;
                parent[set_index] = set_index;
                size_set[set_index] = 1;
                set_index++;
            }
            if (map.find(b) == map.end())
            {
                map[b] = set_index;
                parent[set_index] = set_index;
                size_set[set_index] = 1;
                set_index++;
            }

            union_sets(map[a], map[b]);
            cout << size_set[find(map[a])] << '\n';       
        }
    }
    return 0;
}
