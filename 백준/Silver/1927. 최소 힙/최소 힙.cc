#include <iostream>
#include <vector>

using namespace std;

class MinHeap {
    vector<int> heap;

public:
    void push(int x) {
        heap.push_back(x);
        int idx = heap.size() - 1;

        while (idx > 0) {
            int parent = (idx - 1) / 2;
            if (heap[parent] <= heap[idx]) break;

            swap(heap[parent], heap[idx]);
            idx = parent;
        }
    }

    int top() {
        if (heap.empty()) return 0;
        return heap[0];
    }

    void pop() {
        if (heap.empty()) return;

        heap[0] = heap.back();
        heap.pop_back();

        int idx = 0;
        while (true) {
            int left = idx * 2 + 1;
            int right = idx * 2 + 2;
            int smallest = idx;

            if (left < heap.size() && heap[left] < heap[smallest])
                smallest = left;
            if (right < heap.size() && heap[right] < heap[smallest])
                smallest = right;

            if (smallest == idx) break;

            swap(heap[idx], heap[smallest]);
            idx = smallest;
        }
    }

    bool empty() {
        return heap.empty();
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    MinHeap mh;

    for (int i = 0; i < N; ++i) {
        int x;
        cin >> x;

        if (x == 0) {
            if (mh.empty()) cout << "0\n";
            else {
                cout << mh.top() << "\n";
                mh.pop();
            }
        } else {
            mh.push(x);
        }
    }

    return 0;
}
