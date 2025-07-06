#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    vector<int> temp(citations.begin(), citations.end());
    sort(temp.begin(), temp.end());

    int h_index = 1;
    while (true)
    {   // 인용 횟수
        int cnt = 0;
        for (auto c: temp)
            if (c >= h_index) cnt++;

        if (cnt < h_index) break;
        h_index++;
    }
    return h_index - 1;
}