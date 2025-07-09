#include <iostream>
#include <vector>
#include <numeric>
#include <set>

using namespace std;

int parent[501];
bool is_tree[501]; 

int find(int x)
{
    if (parent[x] == x) 
        return x;
    return parent[x] = find(parent[x]);
}

void union_set(int x, int y)
{
    x = find(x);
    y = find(y);

    if (x == y) {
        is_tree[x] = false; 
        return;
    }

    parent[y] = x; 

    if (!is_tree[x] || !is_tree[y]) {
        is_tree[x] = false;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int case_num = 0;
    while (true)
    {
        case_num++;
        int n, m;
        cin >> n >> m;

        if (n == 0 && m == 0) 
            break; 

        for (int i = 1; i <= n; i++) {
            parent[i] = i;
            is_tree[i] = true;
        }

        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            union_set(u, v);
        }

        set<int> tree_roots; 
        for (int i = 1; i <= n; i++)
        {
            int root = find(i);
            if (is_tree[root]) { 
                tree_roots.insert(root);
            }
        }

        int num_trees = tree_roots.size();

        cout << "Case " << case_num << ": ";
        if (num_trees == 0) {
            cout << "No trees." << endl;
        } else if (num_trees == 1) {
            cout << "There is one tree." << endl;
        } else {
            cout << "A forest of " << num_trees << " trees." << endl;
        }
    }
   
    return 0;
}