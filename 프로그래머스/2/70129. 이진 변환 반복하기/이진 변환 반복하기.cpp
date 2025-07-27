#include <string>
#include <vector>
#include <algorithm>

using namespace std;


string decimalToBinary(int n)
{
    if (n == 0) return "0";

    string binary = "";
    while (n > 0)
    {
        binary = to_string(n % 2) + binary;
        n /= 2;
    }
    reverse(binary.begin(), binary.end());
    return binary;
}

vector<int> solution(string s) {
    vector<int> answer;
    string temp = s;
    int cnt_0 = 0;
    int cnt_1 = 0;
    int cnt_div = 0;

    while (temp != "1")
    {
        cnt_1 = 0;
        for (auto c: temp)
        {
            if (c == '0') cnt_0++;
            else cnt_1++;
        }

        cnt_div++;
        temp = decimalToBinary(cnt_1);
    }
    answer.push_back(cnt_div);
    answer.push_back(cnt_0);
    return answer;
}
