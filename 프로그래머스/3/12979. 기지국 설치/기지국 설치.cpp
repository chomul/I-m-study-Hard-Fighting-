#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int not_radio_index = 0;
    int radio_cover = 2 * w + 1;

    for (int station : stations)
    {
        int start = not_radio_index + 1;
        int end = station - w;

        if (start < end)
        {
            float radio_cnt = ceil(float(end - start) / float(radio_cover));
            answer += static_cast<int>(radio_cnt);
            not_radio_index = station + w;
        }

        not_radio_index = station + w;
    }

    if (not_radio_index < n)
    {
        float radio_cnt = ceil(float(n - not_radio_index) / float(radio_cover));
        answer += static_cast<int>(radio_cnt);
    }
    
    return answer;
}