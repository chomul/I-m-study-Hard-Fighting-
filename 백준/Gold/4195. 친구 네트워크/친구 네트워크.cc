#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

vector<int> parent;
vector<int> setsize;

// Find 함수 (경로 압축)
int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

// Union 함수 (사이즈 갱신)
int union_sets(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) {
        parent[y] = x;
        setsize[x] += setsize[y];
    }
    return setsize[x];
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int F;
        cin >> F;

        unordered_map<string, int> name_to_index;
        parent.clear();
        setsize.clear();

        int next_index = 0;

        for (int i = 0; i < F; ++i) {
            string name1, name2;
            cin >> name1 >> name2;

            // 이름을 정수 인덱스로 매핑
            if (name_to_index.find(name1) == name_to_index.end()) {
                name_to_index[name1] = next_index;
                parent.push_back(next_index);
                setsize.push_back(1);
                next_index++;
            }
            if (name_to_index.find(name2) == name_to_index.end()) {
                name_to_index[name2] = next_index;
                parent.push_back(next_index);
                setsize.push_back(1);
                next_index++;
            }

            int idx1 = name_to_index[name1];
            int idx2 = name_to_index[name2];

            int net_size = union_sets(idx1, idx2);

            cout << net_size << "\n";
        }
    }

    return 0;
}
