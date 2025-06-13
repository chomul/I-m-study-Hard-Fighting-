#include <string>
#include <set>
using namespace std;

int solution(string dirs) {
    int answer = 0;
    
    int curX = 0;
    int curY = 0;
    set<string> road;
    
    for (int i = 0; i < dirs.size(); ++i) 
    {
        if(dirs[i] == 'U' && curY+1 <= 5)
        {
            road.insert(to_string(curX) + to_string(curY) + to_string(curX) + to_string(curY+1));
            road.insert(to_string(curX) + to_string(curY+1) + to_string(curX) + to_string(curY));
            curY++;
        }
        else if(dirs[i] == 'D'&& curY-1 >= -5)
        {
            road.insert(to_string(curX) + to_string(curY) + to_string(curX) + to_string(curY-1));
            road.insert(to_string(curX) + to_string(curY-1) + to_string(curX) + to_string(curY));
            curY--;
        }
        else if(dirs[i] == 'R' && curX+1 <= 5)
        {
            road.insert(to_string(curX) + to_string(curY) + to_string(curX+1) + to_string(curY));
            road.insert(to_string(curX+1) + to_string(curY) + to_string(curX) + to_string(curY));
            curX++;
        }
        else if(dirs[i] == 'L'&& curX-1 >= -5)
        {
            road.insert(to_string(curX) + to_string(curY) + to_string(curX-1) + to_string(curY));
            road.insert(to_string(curX-1) + to_string(curY) + to_string(curX) + to_string(curY));
            curX--;
        } 
    }
    answer = road.size() / 2;
    
    return answer;
}