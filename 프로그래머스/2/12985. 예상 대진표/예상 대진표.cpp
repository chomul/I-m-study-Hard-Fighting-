#include <iostream>

using namespace std;


int win(int node)
{
    if (node % 2 == 0) return node / 2;
    else return node / 2 + 1;
}

int solution(int n, int a, int b)
{
    int answer = 0;

    int node1 = a, node2 = b;
    while (node1 != node2)
    {
        answer++;
        node1 = win(node1);
        node2 = win(node2);
    }
    return answer;
}