#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int answer;
unordered_set<int> horizontal_set;
unordered_set<int> Lcross_set;      // x - y 값이 일정
unordered_set<int> Rcross_set;      // x + y 값이 일정


void dfs(int n, int depth)
{
    if (depth == n)
    {
        answer++;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        int Lcross = depth - i;
        int Rcross = depth + i;
        // 백트래킹
        if (horizontal_set.find(i) != horizontal_set.end() || Lcross_set.find(Lcross) != Lcross_set.end() || Rcross_set.find(Rcross) != Rcross_set.end() ) continue;

        // 재귀 함수 호출 준비 및 처리
        horizontal_set.insert(i);
        Lcross_set.insert(Lcross);
        Rcross_set.insert(Rcross);

        dfs(n, depth + 1);

        horizontal_set.erase(i);
        Lcross_set.erase(Lcross);
        Rcross_set.erase(Rcross);
        
    }
    return;
}

int solution(int n) {

    dfs(n, 0);
    return answer;
}
