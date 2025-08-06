#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;

    // 각 물품의 무게와 가치를 저장할 벡터
    // 0번 인덱스는 사용하지 않고 1번부터 N번까지 사용하기 위해 크기를 N+1로 설정
    vector<int> weights(N + 1);
    vector<int> values(N + 1);

    for (int i = 1; i <= N; ++i) {
        cin >> weights[i] >> values[i];
    }

    // DP 테이블 생성 및 0으로 초기화
    // dp[i][w]: i번째 물품까지 고려하고, 현재 가방 무게가 w일 때의 최대 가치
    vector<vector<int>> dp(N + 1, vector<int>(K + 1, 0));

    // DP 테이블 채우기
    for (int i = 1; i <= N; ++i) { // i: 현재 고려하는 물품 번호
        for (int w = 1; w <= K; ++w) { // w: 가방의 최대 허용 무게
            
            // 현재 물품의 무게가 가방의 허용 무게 w보다 클 경우
            if (weights[i] > w) {
                // 현재 물품 i를 담을 수 없으므로, 이전 상태(i-1)의 값을 그대로 가져옴
                dp[i][w] = dp[i-1][w];
            } 
            // 현재 물품을 담을 수 있는 경우
            else {
                // [선택 1] 현재 물품 i를 담지 않는 경우 (이전 상태의 가치)
                int value_without_item = dp[i-1][w];
                
                // [선택 2] 현재 물품 i를 담는 경우
                // (현재 물품의 가치 + (i-1)번째 물품까지 고려했을 때, 현재 물품 무게를 뺀 무게 한도에서의 최대 가치)
                int value_with_item = values[i] + dp[i-1][w - weights[i]];
                
                // 두 선택 중 더 가치가 높은 쪽을 선택
                dp[i][w] = max(value_without_item, value_with_item);
            }
        }
    }

    // 최종 결과 출력
    // N개의 물품을 모두 고려하고, 가방의 최대 무게가 K일 때의 최대 가치
    cout << dp[N][K] << endl;

    return 0;
}