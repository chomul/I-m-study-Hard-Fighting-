#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, tmp;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < n * n; i++)
    {
        cin >> tmp;

        if(pq.size() < n)
            pq.push(tmp);
        else
        {
            if (tmp > pq.top())
            {
                pq.pop();
                pq.push(tmp);
            }
        }
    }

    cout << pq.top();
}

