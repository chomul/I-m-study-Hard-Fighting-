#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
   
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<int> graph(n + 1);
        vector<int> indegree(n + 1, 0); // 나를 찍은 사람 수 (진입 차수)

        for (int i = 1; i <= n; i++) {
            cin >> graph[i];
            indegree[graph[i]]++; // 지목당한 사람의 카운트 증가
        }
        
        queue<int> q;
        // 1. 처음에 아무에게도 지목받지 못한(0) 학생들을 큐에 넣음
        for (int i = 1; i <= n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        
        int non_team_member_cnt = 0; // 팀에 못 낀 사람 수
        
        // 2. 큐를 돌면서 "탈락자"들이 찍은 사람의 차수를 줄임
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            
            non_team_member_cnt++; // 큐에 들어왔다 = 팀 결성 실패자
            
            int next = graph[cur];
            indegree[next]--; // 내가 나갔으니, 내가 찍은 애의 인기를 1 깎음
            
            // 그 결과, 다음 사람도 인기가 0이 되었다면? -> 걔도 탈락 확정
            if (indegree[next] == 0) {
                q.push(next);
            }
        }
        
        // 정답은 바로 탈락자 수
        cout << non_team_member_cnt << '\n';
    }
    return 0;
}