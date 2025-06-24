#include <string>
#include <vector>
#include <stack>

using namespace std;

string solution(int n, int k, vector<string> cmd) {
    vector<int> prev(n), next(n);
    vector<bool> alive(n, true);
    stack<int> deleted;

    for (int i = 0; i < n; ++i) {
        prev[i] = i - 1;
        next[i] = i + 1;
    }
    next[n - 1] = -1;

    int cur = k;

    for (const string& c : cmd) {
        if (c[0] == 'U') {
            int x = stoi(c.substr(2));
            while (x--) cur = prev[cur];
        } else if (c[0] == 'D') {
            int x = stoi(c.substr(2));
            while (x--) cur = next[cur];
        } else if (c[0] == 'C') {
            alive[cur] = false;
            deleted.push(cur);

            if (prev[cur] != -1) next[prev[cur]] = next[cur];
            if (next[cur] != -1) prev[next[cur]] = prev[cur];

            cur = (next[cur] != -1) ? next[cur] : prev[cur];
        } else if (c[0] == 'Z') {
            int rec = deleted.top(); deleted.pop();
            alive[rec] = true;

            if (prev[rec] != -1) next[prev[rec]] = rec;
            if (next[rec] != -1) prev[next[rec]] = rec;
        }
    }

    string answer;
    for (int i = 0; i < n; ++i)
        answer += (alive[i] ? 'O' : 'X');

    return answer;
}