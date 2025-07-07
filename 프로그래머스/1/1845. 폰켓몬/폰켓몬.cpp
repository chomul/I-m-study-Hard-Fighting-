#include <vector>
#include <unordered_set>

using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    unordered_set<int> set;
    for (auto num : nums)
        set.insert(num);

    int get_num = nums.size() / 2;
    answer = min(get_num, (int)set.size());
    return answer;
}