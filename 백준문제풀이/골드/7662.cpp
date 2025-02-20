#include <iostream>
#include <set>
#include<vector>
#include<queue>
#include <algorithm>
#include <unordered_map>

using namespace std;
//set이용 

class Que {
public:
    multiset<int> arr;
    
    void insert(int num) {
        arr.insert(num);  
        
    }

    void frontpop() {
        if (!arr.empty()) {
            arr.erase(arr.begin());  
        }
    }

    void rearpop() {
        if (!arr.empty()) {
            auto it = prev(arr.end());
            arr.erase(it);  
        }
    }

    void printfront() {
        if (arr.empty()) {
            return;
        }
        cout <<  " " << * arr.begin() << '\n';  
    }

    void printrear() {
        if (arr.empty()) {
            cout << "EMPTY\n";
            return;
        }
        cout << *prev(arr.end()); 
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;

    while (tc--) {
        Que q;
        int num;
        cin >> num;

        char str;
        int number;
        for (int i = 0; i < num; i++) {
            cin >> str;
            if (str == 'I') {
                cin >> number;
                q.insert(number);
            }
            else if (str == 'D') {
                cin >> number;
                if (number == -1) q.frontpop();
                else q.rearpop();
            }
        }

        q.printrear();
        q.printfront();
    }

    return 0;
}

//우선순위 큐 두개사용
/*
class SyncQueue {
public:
    priority_queue<int> maxheap;
    priority_queue<int, vector <int>, greater<int>> minheap;
    unordered_map <int, int> um;
    void sync() {

        while (!maxheap.empty() && um[maxheap.top()] == 0) {
            maxheap.pop();
        }

        while (!minheap.empty() && um[minheap.top()] == 0)
            minheap.pop();
    }

    void insert(int number) {
        maxheap.push(number);
        minheap.push(number);
        um[number]++;
    }

    void deletemax() {
        if (maxheap.empty())
            return;
      
        um[maxheap.top()]--;
        maxheap.pop();
        sync();

    }

    void deletemin() {
        if (minheap.empty())
            return;
        um[minheap.top()]--;
        minheap.pop();
        sync();
    }
    
    bool isEmpty() {
        return minheap.size() == 0 && maxheap.size() == 0;
    }


};



int main() {

    int tc;

    cin >> tc;

    int num;
    while (tc--) {
        cin >> num;
        
        SyncQueue sq;
        
        char str;
        int number;
        for (int i = 0; i < num; i++) {
            cin >> str;
            if (str == 'I') {
                cin >> number;
                sq.insert(number);
            }
            else if (str == 'D') {
                cin >> number;
                if (number == -1) {
                    sq.deletemin();
                }
                else {
                    sq.deletemax();
                }
            }
        }

        if (sq.isEmpty())
            cout << "EMPTY" << '\n';
        else
            cout << sq.maxheap.top() << " " << sq.minheap.top() << "\n";

        

    }


}*/