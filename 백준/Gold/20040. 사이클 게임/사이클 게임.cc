#include <iostream>

using namespace std;

int parent[500002];

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

int main(int argc, char* argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin>>n>>m;
    int cnt = 0;

    for (int i = 1; i <= n; i++) parent[i] = i; 
    
    while (m--)
    {
        int a, b;
        cin>>a>>b;
        cnt++;
        if (!union_set(a, b)) 
        {
            cout << cnt << endl;
            return 0;
        }
    }

    cout << 0 << endl;
   
    return 0;
}
