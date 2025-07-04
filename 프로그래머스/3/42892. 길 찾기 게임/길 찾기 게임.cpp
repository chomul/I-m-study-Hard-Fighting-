#include <string>
#include <vector>
#include <algorithm>

using namespace std;
struct Node
{
    int x, y, idx;
    Node* left;
    Node* right;

    Node(int x, int y, int idx)
    {
        this->x = x;
        this->y = y;
        this->idx = idx;
        this->left = nullptr;
        this->right = nullptr;
    }
};

bool compare(Node* a, Node* b)
{
    if (a->y == b->y) return a->x < b->x;
    return a->y > b->y;
}

void insertNode(Node* parent, Node* child)
{
    if (parent->x > child->x)
    {
        if (parent->left == nullptr)
            parent->left = child;
        else
            insertNode(parent->left, child);
    }
    else
    {
        if (parent->right == nullptr)
            parent->right = child;
        else
            insertNode(parent->right, child);       
    }
}

void preorder(Node* node, vector<int>& answer)
{
    if (node == nullptr) return;
    answer.push_back(node->idx);
    preorder(node->left, answer);
    preorder(node->right, answer);
}

void postorder(Node* node, vector<int>& answer)
{
    if (node == nullptr) return;
    postorder(node->left, answer);
    postorder(node->right, answer);
    answer.push_back(node->idx);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) 
{
    vector<vector<int>> answer;

    vector<Node*> nodearr;
    for (int i = 0; i < nodeinfo.size(); i++)
        nodearr.push_back(new Node(nodeinfo[i][0], nodeinfo[i][1], i + 1));

    sort(nodearr.begin(), nodearr.end(), compare);

    Node* parent = nodearr[0];
    for (int i = 1; i < nodearr.size(); i++)
        insertNode(parent, nodearr[i]);

    vector<int> pre;
    vector<int> post;
    preorder(parent, pre);
    postorder(parent, post);

    answer.push_back(pre);
    answer.push_back(post);
    
    return answer;
}