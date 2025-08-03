#include <string>
#include <vector>

using namespace std;

int solution(int n) {

    vector<long long> v(n + 1, 0);
    v[1] = 1;
    for (int i = 2; i <= n; i++)
        v[i] = v[i - 1] % 1234567 + v[i - 2] % 1234567;
    
    return static_cast<int>(v[n] % 1234567);
}