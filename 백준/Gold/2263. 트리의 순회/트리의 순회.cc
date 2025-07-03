#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

vector<int> inorder;
vector<int> postorder;
unordered_map<int, int> inorder_index;

void backup(int in_start, int in_end, int post_start, int post_end)
{
    if (in_start > in_end || post_start > post_end) return;

    int root = postorder[post_end];
    cout << root << " ";
    
    int root_index = inorder_index[root];
    int left_size = root_index - in_start;

    backup(in_start, root_index - 1, post_start, post_start + left_size - 1);
    backup(root_index + 1, in_end, post_start + left_size, post_end - 1);
}

int main(int argc, char* argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    for (int i = 1; i <= n; i++)
    {
        int temp;
        cin >> temp;
        inorder.push_back(temp);
    }
    for (int i = 1; i <= n; i++)
    {
        int temp;
        cin >> temp;
        postorder.push_back(temp);
    }    
    
    for (int i = 0; i < n; ++i) 
        inorder_index[inorder[i]] = i;

    backup(0, n - 1, 0, n - 1);
    
    return 0;
}
