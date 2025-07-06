#include <string>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

bool compare(tuple<string, string, string, int> a, tuple<string, string, string, int> b)
{
    string temp1, temp2;
    for (auto i : get<0>(a))
        temp1 += tolower(i);
    for (auto i : get<0>(b))
        temp2 += tolower(i);
    
    if (temp1 != temp2) return temp1 < temp2;

    int num_a = stoi(get<1>(a));
    int num_b = stoi(get<1>(b));

    if (num_a != num_b) return num_a < num_b;

    return get<3>(a) < get<3>(b);
}

vector<string> solution(vector<string> files){
    vector<string> answer = files;

    vector<tuple<string, string, string, int>> temp;

    for (int i = 0; i < files.size(); i++)
    {
        int idx = 0;
        string head = "", number = "", tail = "";

        while (idx < files[i].size() && !isdigit(files[i][idx])) {
            head += files[i][idx++];
        }

        while (idx < files[i].size() && isdigit(files[i][idx]) && number.size() < 5) {
            number += files[i][idx++];
        }

        tail = files[i].substr(idx);
        
        temp.push_back(make_tuple(head, number, tail, i));
    }

    sort(temp.begin(), temp.end(), compare);
    answer.clear();
    for (auto c : temp)
        answer.push_back(get<0>(c) + get<1>(c) + get<2>(c));

    return answer;
}