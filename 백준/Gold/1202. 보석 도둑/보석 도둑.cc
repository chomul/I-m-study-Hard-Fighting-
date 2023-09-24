#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, k;
    cin >> n >> k;
    
    vector<pair<int, int>> jewels(n);
    vector<int> bags(k);
    
    for (int i = 0; i < n; ++i) {
        cin >> jewels[i].first >> jewels[i].second; // 보석의 가치와 무게 순서 변경
    }
    
    for (int i = 0; i < k; ++i) {
        cin >> bags[i];
    }
    
    sort(jewels.begin(), jewels.end());
    sort(bags.begin(), bags.end());
    
    long long sum = 0;
    priority_queue<int> available_jewels;
    
    for (int i = 0, j = 0; i < k; ++i) {
        while (j < n && jewels[j].first <= bags[i]) {
            available_jewels.push(jewels[j].second);
            j++;
        }
        if (!available_jewels.empty()) {
            sum += available_jewels.top();
            available_jewels.pop();
        }
    }
    
    cout << sum << endl;
    
    return 0;
}
