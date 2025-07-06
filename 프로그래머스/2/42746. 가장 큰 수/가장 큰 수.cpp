#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> number;

    for (int i = 0; i < numbers.size(); i++)
        number.push_back(to_string(numbers[i]));
    sort(number.begin(), number.end(), [](string a, string b)
    {
        return a + b > b + a;
    });
    for (auto c: number)
        answer += c;
    
    return answer[0] == '0' ? "0" : answer;
}
