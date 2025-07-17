#include <bits/stdc++.h>
using namespace std;

// 전체 노드 수 (0번은 출발, 32번은 도착)
const int N = 33;
const int END = 32;

// 각 칸의 점수
int score[N] = {
    0,  2,  4,  6,  8, 10, 12, 14, 16, 18,
   20, 22, 24, 26, 28, 30, 32, 34, 36, 38,
   40, 13, 16, 19, 25, 30, 35, 22, 24, 28,
   27, 26,  0
};

// 이동 경로: nxt[i][0]=직진, nxt[i][1]=분기(없으면 -1)
int nxt[N][2];

// 주사위 10번
int dice[10];
// 말 4개 위치
int pos[4];
// 정답
int best = 0;

// 보드 초기화
void init() {
    // 기본 네트워크: i→i+1
    for (int i = 0; i < N; i++) {
        nxt[i][0] = i + 1;
        nxt[i][1] = -1;
    }
    // 20점(20번) 이후는 곧장 도착
    nxt[20][0] = END;
    nxt[END][0] = END;

    // 분기 지점 설정
    // 10점(5번)→13점(21번)
    nxt[5][1]  = 21;
    // 20점(10번)→22점(27번)
    nxt[10][1] = 27;
    // 30점(15번)→28점(29번)
    nxt[15][1] = 29;

    // 분기된 경로들 연결
    // 13(21)→16(22)→19(23)→25(24)→30(25)→35(26)→40(20)
    nxt[21][0]=22; nxt[22][0]=23; nxt[23][0]=24;
    nxt[24][0]=25; nxt[25][0]=26; nxt[26][0]=20;
    // 22(27)→24(28)→25(24)
    nxt[27][0]=28; nxt[28][0]=24;
    // 28(29)→27(30)→26(31)→25(24)
    nxt[29][0]=30; nxt[30][0]=31; nxt[31][0]=24;
}

// 한 말을 dist칸 이동시키고 최종 위치 반환
int move_one(int start, int dist) {
    int cur = start;
    for (int step = 0; step < dist; ++step) {
        // 첫 걸음에 분기할 수 있으면 분기
        if (step==0 && nxt[cur][1] != -1)
            cur = nxt[cur][1];
        else
            cur = nxt[cur][0];
    }
    return cur;
}

// DFS로 10번 턴 완전탐색
void dfs(int turn, int sum) {
    if (turn == 10) {
        best = max(best, sum);
        return;
    }
    int d = dice[turn];
    for (int i = 0; i < 4; ++i) {
        int old = pos[i];
        // 이미 도착 지점이면 움직일 수 없음
        if (old == END) continue;

        int nxtp = move_one(old, d);
        // 충돌 검사 (도착 END는 예외)
        if (nxtp != END) {
            bool collide = false;
            for (int j = 0; j < 4; ++j) {
                if (i!=j && pos[j]==nxtp) {
                    collide = true; break;
                }
            }
            if (collide) continue;
        }
        // 이동 & 재귀
        pos[i] = nxtp;
        dfs(turn+1, sum + score[nxtp]);
        // 되돌리기
        pos[i] = old;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 0; i < 10; ++i)
        cin >> dice[i];
    init();
    dfs(0, 0);
    cout << best;
    return 0;
}
