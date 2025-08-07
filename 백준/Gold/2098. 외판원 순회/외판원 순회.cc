#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9; // 무한대를 나타내는 큰 값 (문제의 최대 비용보다 커야 함)
int N;
vector<vector<int>> W;
vector<vector<int>> dp;

// solve(현재 도시, 방문한 도시 비트마스크)
int solve(int current_city, int visited_mask) {
    // 1. 모든 도시를 방문한 경우
    if (visited_mask == (1 << N) - 1) {
        // 출발 도시(0)로 돌아가는 경로가 있는 경우
        if (W[current_city][0] != 0) {
            return W[current_city][0];
        }
        // 경로가 없는 경우 (선택되면 안 되므로 무한대 반환)
        return INF;
    }

    // 2. 이미 계산된 문제인 경우 (메모이제이션)
    if (dp[current_city][visited_mask] != -1) {
        return dp[current_city][visited_mask];
    }

    // 3. 재귀적으로 최소 비용 계산
    // 현재 상태의 dp값을 INF로 초기화
    dp[current_city][visited_mask] = INF;

    for (int next_city = 0; next_city < N; ++next_city) {
        // 다음 도시를 아직 방문하지 않았고, 길이 있는 경우
        if (!(visited_mask & (1 << next_city)) && W[current_city][next_city] != 0) {
            // (현재 -> 다음 도시 비용) + (다음 도시에서 나머지 도시를 방문하는 최소 비용)
            int cost = W[current_city][next_city] + solve(next_city, visited_mask | (1 << next_city));
            
            // 기존의 최소 비용과 비교하여 갱신
            dp[current_city][visited_mask] = min(dp[current_city][visited_mask], cost);
        }
    }

    return dp[current_city][visited_mask];
}

int main() {
    // 빠른 입출력
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    // 비용 행렬과 dp 테이블 크기 동적 할당
    W.assign(N, vector<int>(N));
    dp.assign(N, vector<int>(1 << N, -1)); // dp 테이블을 -1로 초기화 (방문하지 않음 의미)

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> W[i][j];
        }
    }

    // 0번 도시에서 출발 (0번 도시 방문 처리)
    int result = solve(0, 1);

    cout << result << "\n";

    return 0;
}