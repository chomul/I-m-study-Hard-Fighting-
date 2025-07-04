#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

vector<string> solution(vector<string> orders, vector<int> course)
{   
    vector<string> answer;

    for (int c_len : course) {
        unordered_map<string, int> counter;
        int max_val = 0;

        for (string order : orders) {
            if (order.size() < c_len) continue;

            sort(order.begin(), order.end());  // 항상 정렬

            vector<bool> select(order.size(), false);
            fill(select.begin(), select.begin() + c_len, true);

            do {
                string comb;
                for (int i = 0; i < order.size(); i++) {
                    if (select[i]) comb += order[i];
                }
                counter[comb]++;
                max_val = max(max_val, counter[comb]);
            } while (prev_permutation(select.begin(), select.end()));
        }

        for (auto& [k, v] : counter) {
            if (v >= 2 && v == max_val) {
                answer.push_back(k);
            }
        }
    }

    sort(answer.begin(), answer.end());
    return answer;
}