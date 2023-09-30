#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
using namespace std;

vector<int> adg[100001];
int p[100001];

void bfs(int root)
{
    queue<int> q;
    q.push(root);
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (auto nxt : adg[cur])
        {
            if (p[cur] == nxt) continue; 
            q.push(nxt);
            p[nxt] = cur;
        }
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, a, b;
    cin >> n ;

    for (int i = 0; i < n-1; i++)
    {
        cin >> a >> b;
        adg[a].push_back(b);
        adg[b].push_back(a);
    }
    bfs(1);

    for (int i = 2; i <= n; i++)
        cout << p[i] << '\n';

    return 0;
}

