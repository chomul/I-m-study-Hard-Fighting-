#include <iostream>
using namespace std;

int solution(int n)
{
    int ans = 0;

    while (n > 0)
    {
        if (n % 2 != 0)
        {
            ans++;
            n--;
        }
        else
        {
            n /= 2;
        }
    }

    return ans;
}
