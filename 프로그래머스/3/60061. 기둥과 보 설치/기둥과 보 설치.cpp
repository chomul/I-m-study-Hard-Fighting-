#include <string>
#include <vector>
#include <set>

using namespace std;

bool can_install(int x, int y, int type, const set<vector<int>>& structures) {
    if (type == 0)
    { // 기둥 (Column)
        // 규칙 1: 바닥 위에 있을 때
        if (y == 0) return true;
        // 규칙 2: 다른 기둥 위에 있을 때
        if (structures.count({x, y - 1, 0})) return true;
        // 규칙 3: 보의 한쪽 끝 부분 위에 있을 때
        if (structures.count({x - 1, y, 1}) || structures.count({x, y, 1})) return true;
    } else
    { // 보 (Beam)
        // 규칙 1: 한쪽 끝 부분이 기둥 위에 있을 때
        if (structures.count({x, y - 1, 0}) || structures.count({x + 1, y - 1, 0})) return true;
        // 규칙 2: 양쪽 끝 부분이 다른 보와 동시에 연결되어 있을 때
        if (structures.count({x - 1, y, 1}) && structures.count({x + 1, y, 1})) return true;
    }
    return false; 
}


vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    set<vector<int>> structures;

    for (const auto& frame : build_frame) {
        int x = frame[0];
        int y = frame[1];
        int type = frame[2];  // 0: 기둥, 1: 보
        int action = frame[3]; // 0: 삭제, 1: 설치

        if (action == 1)
        { // 설치
            // 설치 가능 조건을 만족하면 구조물 추가
            if (can_install(x, y, type, structures)) 
                structures.insert({x, y, type});
        }
        else
        { // 삭제
            // 1. 해당 구조물이 존재하는지 확인 후, 임시로 삭제
            if (structures.count({x, y, type})) {
                structures.erase({x, y, type});

                // 2. 삭제 후 남아있는 모든 구조물이 유효한지 검사
                bool is_stable = true;
                for (const auto& s : structures)
                {
                    // 하나라도 설치 조건을 만족하지 못하면 불안정한 상태
                    if (!can_install(s[0], s[1], s[2], structures)) {
                        is_stable = false;
                        break;
                    }
                }

                // 3. 불안정하다면 삭제를 취소 (원상 복구)
                if (!is_stable) {
                    structures.insert({x, y, type});
                }
            }
        }
    }
    
    vector<vector<int>> answer(structures.begin(), structures.end());
    return answer;
}