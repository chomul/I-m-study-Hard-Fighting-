#include <iostream>
#include <map>
#include <queue>
#include <tuple>
#include <vector>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;
    
    // 세그먼트 트리 생성
    int base_cnt = 0;
    int vec_size = 1;
    while (true)
    {
        if (n <= vec_size)
        {
            base_cnt = vec_size;
            int temp = vec_size;
            while (temp)
            {
                temp /= 2;
                vec_size += temp;
            }
            break;
        }
        vec_size *= 2;
    }
    vector<long long> v(vec_size, 0);

    for (int i = 0; i < n; i++)
        cin >> v[i];
    
    for (int i = 0; i < vec_size; i++)
    {
        int insert_index = i / 2 + base_cnt;
        if (insert_index < vec_size)
            v[insert_index] += v[i];
    }

    int temp = m + k;
    while (temp--)
    {
        int a;
        long long b, c;
        cin >> a >> b >> c;
        b--;
        if (a == 1) // 숫자 변경
        {
            v[b] = c;
            int insert_index = b / 2 + base_cnt;
            int prev_index = b;
            while (insert_index < vec_size)
            {
                if (prev_index % 2 == 0) v[insert_index] = v[prev_index] + v[prev_index + 1];
                else v[insert_index] = v[prev_index] + v[prev_index - 1];
                prev_index = insert_index;
                insert_index = insert_index / 2 + base_cnt;
            }
        }
        else if (a == 2) // 합 구하기
        {
            c--;
            long long sum = 0;
            while (b <= c)
            {
                if (b % 2 == 1)
                {
                    sum += v[b];
                    b++;
                }
                if (c % 2 == 0)
                {
                    sum += v[c];
                    c--;
                }
                b = b / 2 + base_cnt;
                c = c / 2 + base_cnt;
            }
            cout << sum << '\n';
        }
    }

    return 0;

} 