#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x, sum = 0;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < n; i++)
    {
        cin >> x;
        pq.emplace(x);
    }

    int tmp;
    while (pq.size() != 1)
    {

        tmp = pq.top();
        pq.pop();
        tmp += pq.top();
        pq.pop();
        pq.emplace(tmp);
        sum += tmp;
    }

    cout << sum;
}

