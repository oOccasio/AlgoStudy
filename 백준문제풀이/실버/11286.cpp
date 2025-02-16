#include <iostream>
#include <unordered_map>
#include <stack>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct value {
    int num;
    int value;
};


class Heap {
public:
    int size;
    int front;
    int rear;
    value* arr;

    Heap() {
        size = 0;
        front = 1;
        rear = 0;
        arr = new value[100000]();
    }

    void Push(int num) {
     
        arr[++rear].num = num;
        if (num < 0)
            num *= -1;
        arr[rear].value = num;
        int index = rear;

        while (index > 1) {
            if (index % 2 == 0)
                if (arr[index / 2].value > arr[index].value) {
                    swap(arr[index / 2], arr[index]);
                    index = index / 2;
                }
                
                else if (arr[index / 2].value == arr[index].value) {
                    if (arr[index / 2].num > arr[index].num) {
                        swap(arr[index / 2], arr[index]);
                        index = index / 2;
                    }
                    else
                        break;
                }
                
                else
                    break;
            else
                if (arr[(index - 1) / 2].value > arr[index].value) {
                    swap(arr[(index - 1) / 2], arr[index]);
                    index = (index - 1) / 2;
                }
                
                else if (arr[(index - 1) / 2].value == arr[index].value) {
                    if (arr[(index - 1) / 2].num > arr[index].num) {
                        swap(arr[(index - 1) / 2], arr[index]);
                        index = (index - 1) / 2;
                    }
                    else
                        break;
                }
                
                else
                    break;
        }
        size++;
    }


    bool empty() {
        return size == 0;
    }

    int Pop() {
        if (empty())
            return 0;
       
        int result = arr[1].num;
        rear--;
        arr[1] = arr[size--];
        Sort(1);

        return result;
       

    }

    void Sort(int index) {
        int right = index * 2;
        int left = index * 2 + 1;
        int smallest = index;

        if (left <= size && arr[left].value < arr[smallest].value)
            smallest = left;
        else if (left <= size && arr[left].value == arr[smallest].value)
            if (arr[left].num < arr[smallest].num)
                smallest = left;

        if (right <= size && arr[right].value < arr[smallest].value)
            smallest = right;
        else if (right <= size && arr[right].value == arr[smallest].value)
            if (arr[right].num < arr[smallest].num)
                smallest = right;

        if (smallest != index) {
            swap(arr[smallest], arr[index]);
            Sort(smallest);
        }

    }

};




int main() {


    int tc;

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Heap heap;

    cin >> tc;

    while (tc--) {

        int num;

        cin >> num;

        if (num == 0)
            cout << heap.Pop() << '\n';
        else
            heap.Push(num);
            


    }
    
    
    return 0;
}



