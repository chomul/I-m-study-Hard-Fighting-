#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
using namespace std;

vector<int> adg[30];
int lc[30];
int rc[30];

void preorder(int cur) {
    cout << char(cur + 'A' - 1);
    if (lc[cur] != 0) preorder(lc[cur]);
    if (rc[cur] != 0) preorder(rc[cur]);
}

void inorder(int cur) {
    if (lc[cur] != 0) inorder(lc[cur]);
    cout << char(cur + 'A' - 1);
    if (rc[cur] != 0) inorder(rc[cur]);
}

void postorder(int cur) {
    if (lc[cur] != 0) postorder(lc[cur]);
    if (rc[cur] != 0) postorder(rc[cur]);
    cout << char(cur + 'A' - 1);
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    char a, b, c;
    cin >> n ;

    for (int i = 0; i < n; i++)
    {
        cin >> a >> b >> c;
        if (b != '.') lc[a - 'A' + 1] = b - 'A' + 1;
        if (c != '.') rc[a - 'A' + 1] = c - 'A' + 1;
    }

    preorder(1); cout << '\n';
    inorder(1); cout << '\n';
    postorder(1); cout << '\n';

    return 0;
}

