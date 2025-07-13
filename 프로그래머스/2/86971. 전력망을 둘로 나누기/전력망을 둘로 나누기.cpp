#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;


#define SIZE 102

int parent[SIZE];

int find(int x)
{
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}

void union_set(int x, int y)
{
    int a = find(x);
    int b = find(y);
    if (a == b) return;
    parent[a] = b;
    return;
}


int solution(int n, vector<vector<int>> wires) {
    int answer = -1;

    vector<int> min_cnt;
    
    for (int i = 0; i < wires.size(); i++)
    {
        for (int j = 0; j < n; j++)
            parent[j] = j;
        
        for (int j = 0; j < wires.size(); j++)
        {
            if (i == j) continue;
            
            union_set(wires[j][0], wires[j][1]);
        }

        int temp_value = find(0);
        int temp1 = 1;
        int temp2 = 0;
        
        for (int j = 1; j < n; j++)
        {
            if (find(j) == temp_value) temp1++;
            else temp2++;
        }

        min_cnt.push_back(abs(temp1 - temp2));

        for (int j = 0; j < SIZE; j++)
            parent[j] = 0;
    }

    answer = *min_element(min_cnt.begin(), min_cnt.end());
    return answer;
}