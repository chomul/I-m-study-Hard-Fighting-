#include <string>
#include <vector>

using namespace std;

int solution(int n) {

    vector<long long> v(n + 1, 0);
    v[1] = 1;
    v[2] = 2;

    for (int i = 3; i <= n; i++)
        v[i] = v[i - 1] % 1000000007 + v[i - 2] % 1000000007;
    
    return static_cast<int>(v[n] % 1000000007);
}