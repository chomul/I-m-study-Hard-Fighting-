#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> keyinput, vector<int> board) {
    vector<int> answer;

    pair<int, int> pos = {0, 0};
    int x_limit = (board[0] - 1) / 2;
    int y_limit = (board[1] - 1) / 2;
    for (auto key : keyinput)
    {
        if (key == "left")
        {
            if (pos.first > -x_limit)
                pos.first--;
        }
        else if (key == "right")
        {
            if (pos.first < x_limit)
                pos.first++;
        }
        else if (key == "up")
        {
            if (pos.second < y_limit)
                pos.second++;
        }
        else if (key == "down")
        {
            if (pos.second > -y_limit)
                pos.second--;
        }
    }
    answer.push_back(pos.first);
    answer.push_back(pos.second);
    return answer;
}
