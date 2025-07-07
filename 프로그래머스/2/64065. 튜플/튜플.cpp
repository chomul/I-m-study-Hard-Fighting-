#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<int> solution(string s) {
 vector<int> answer;

    // 숫자 등장 횟수 카운트 (1~100000 범위 가정)
    vector<int> count(100001, 0);
    string str;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '{') continue;

        if (isdigit(s[i])) {
            str += s[i];
        }
        else if (s[i] == ',' || s[i] == '}') {
            if (!str.empty()) {
                int num = stoi(str);
                count[num]++;
                str.clear();
            }
        }
    }

    // 등장 횟수를 기반으로 정렬
    vector<pair<int, int>> v;
    for (int i = 1; i < count.size(); ++i) {
        if (count[i] > 0) {
            v.push_back({i, count[i]});
        }
    }

    sort(v.begin(), v.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    });

    for (auto& p : v)
        answer.push_back(p.first);

    return answer;
}