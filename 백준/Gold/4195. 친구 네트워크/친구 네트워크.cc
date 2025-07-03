#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;


vector<int> parent(200002, -1);
vector<int> setsize(200002, 0);

// 들어있는 집합 번호 찾기
int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

// 루트를 집합에 포함
int union_sets(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) {
        parent[y] = x;
        setsize[x] += setsize[y];
    }
    return setsize[x];
}

void solution()
{
    int F;
    cin >> F;

    unordered_map<string, int> name_to_index;
    for (int i = 0; i < 100001; ++i) {
        parent[i] = -1;
        setsize[i] = 0;
    }

    // 집합 번호
    int set_index = 1;
    for (int i = 0; i < F; ++i)
    {
        string name1, name2;
        cin >> name1 >> name2;

        // 이름을 정수 인덱스로 매핑
        if (name_to_index.find(name1) == name_to_index.end())
        {
            name_to_index[name1] = set_index;
            parent[set_index] = set_index;
            setsize[set_index]++;
            set_index++;
        }
        if (name_to_index.find(name2) == name_to_index.end())
        {
            name_to_index[name2] = set_index;
            parent[set_index] = set_index;
            setsize[set_index]++;
            set_index++;
        }

        int idx1 = name_to_index[name1];
        int idx2 = name_to_index[name2];

        int net_size = union_sets(idx1, idx2);

        cout << net_size << "\n";
    }
}

int main(int argc, char* argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solution();

    return 0;
}
