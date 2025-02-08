#include <iostream>
using namespace std;

class MinHeap {
private:
    int size = 0;
    int* arr;

public:
    MinHeap() {
        arr = new int[200002]();
    }

    ~MinHeap() {
        delete[] arr;
    }

    void Push(int num) {
        arr[++size] = num;
        int index = size;

        while (index > 1) {
            int parent = index / 2;
            if (arr[parent] > arr[index]) {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else {
                break;
            }
        }
    }

    int Pop() {
        if (IsEmpty()) return 0;

        int result = arr[1];
        arr[1] = arr[size--];
        Sort(1);

        return result;
    }

    void Sort(int index) {
        int left = index * 2;
        int right = index * 2 + 1;
        int smallest = index;


        if (left <= size && arr[left] < arr[smallest]) {
            smallest = left;
        }

        if (right <= size && arr[right] < arr[smallest]) {
            smallest = right;
        }


        if (smallest != index) {
            swap(arr[smallest], arr[index]);
            Sort(smallest);
        }
    }

    bool IsEmpty() {
        return size == 0;
    }
};

int main() {
    int N;
    cin >> N;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    MinHeap heap;
    int num;

    while (N--) {
        cin >> num;

        if (num == 0) {
            if (heap.IsEmpty()) {
                cout << 0 << '\n';
            }
            else {
                cout << heap.Pop() << '\n';
            }
        }
        else {
            heap.Push(num);
        }
    }

    return 0;
}
