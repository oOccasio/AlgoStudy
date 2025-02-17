#include <iostream>
#include <unordered_map>
#include <stack>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class deq {
public:
    int size;
    int rear;
    int front;
    int* arr;

    deq() {
        size = 0;
        rear = -1;
        front = 0;
        arr = new int[100000]();
    }

    void Push(int num) {
        arr[++rear] = num;
        size++;
    }

    int Pop(bool reverse) {
        if (isEmpty() == 1) {
            return -1;
        }
            
        
        
        if (reverse) {
            size--;
            return arr[rear--];
        }
        else {
            size--;
            return arr[front++];
        }

    }

    bool isEmpty() {
        return size == 0;
    }

    int dqsize() {
        return size;
    }

};




int main() {



    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    int tc;
    cin >> tc;

    string str;
    int num;
    string number;
    

    while (tc--) {
        bool reverse = 0;
        bool error = 0;
        cin >> str;
        cin >> num;

        deq dq;
        
        cin >> number;
        int tmp = 0;
        for (int i = 0; i < number.size() && num != 0; i++) {
           
            if (number[i] >= '0' && number[i] <= '9')
                tmp = tmp * 10 + number[i] - '0';
            if (number[i] == ',' || number[i] == ']') {
                dq.Push(tmp);
                tmp = 0;
            }

        }
        

        for (int i = 0; i < str.size(); i++) {
            if (str[i] == 'R' && reverse == 0)
                reverse = 1;
            else if (str[i] == 'R' && reverse == 1)
                reverse = 0;
            if (str[i] == 'D') {
                if (dq.Pop(reverse) == -1) {
                    error = 1;
                    break;

                }
                    

            }
                
        }

        if (error)
            cout << "error" << '\n';

        else if (dq.dqsize() == 0)
            cout << "[]" << '\n';
        else {
            cout << '[';
            while (dq.dqsize() > 1) {
                cout << dq.Pop(reverse) << ',';
                
            }
            cout << dq.Pop(reverse) << ']' << '\n';
        }

    }



    return 0;
}



