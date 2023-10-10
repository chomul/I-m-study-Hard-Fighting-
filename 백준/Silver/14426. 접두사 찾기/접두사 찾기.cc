#include <bits/stdc++.h>
#include "unordered_set"
using namespace std;

const int ROOT = 1;
int unused = 2;
const int MX = 10000 * 500 + 5; // 최대 등장 가능한 글자의 수
bool chk[MX];                   // 문자열의 끝인지 여부를 저장하는 함수
int nxt[MX][26];                // 각 정점에서 자식 정점의 번호
int cnt = 0;

int c2i(char c)                 // 글자를 받아 인덱스로 사용할 수 있도록 변환
{
    return c - 'a';
}

void insert(string& s)
{
    int cur = ROOT;
    for (auto c : s)
    {
        if (nxt[cur][c2i(c)] == -1)   // 첫번째 문자가 같은게 없을 경우
            nxt[cur][c2i(c)] = unused++;
        cur = nxt[cur][c2i(c)];
    }
    chk[cur] = true;
}

void find(const string& s)
{
    int cur = ROOT;
    for (auto c : s)
    {
        if (nxt[cur][c2i(c)] == -1)
            return;
        cur = nxt[cur][c2i(c)];
    }
    cnt++;
    return;
}

int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < MX; i++)
        fill(nxt[i], nxt[i] + 26, -1);

    int n, m;
    cin >> n >> m;

    while (n--)
    {
        string s;
        cin >> s;
        insert(s);
    }

    while (m--)
    {
        string s;
        cin >> s;
        find(s);
    }

    cout << cnt;
}