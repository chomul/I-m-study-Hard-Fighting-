#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;

    unordered_map<int, int> left_topping_map, right_topping_map;

    for (int i = 0; i < topping.size(); i++)
        left_topping_map[topping[i]]++;

    for (int i = topping.size() - 1; i >= 0; i--)
    {
        right_topping_map[topping[i]]++;
        left_topping_map[topping[i]]--;
        if (left_topping_map[topping[i]] == 0) left_topping_map.erase(topping[i]);
        if (right_topping_map.size() == left_topping_map.size()) answer++;
    }    

    return answer;
}