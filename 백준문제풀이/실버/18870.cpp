#include <iostream>
#include <unordered_map>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

struct number {
    int index;
    int value;
};


bool compare1(number x, number y) {
    return x.value < y.value;
}

bool compare2(number x, number y) {
    return x.index < y.index;
}





int main() {
    
    int num;
    cin >> num;

    vector <number> arr(num);

    int num1;
    for (int i = 0; i < num; i++) {
        cin >> num1;
        arr[i].index = i;
        arr[i].value = num1;
    }

    sort(arr.begin(), arr.end(), compare1);

    int index = 0;
    for(int i = 0 ; i < num - 1; i++) {       
        if (arr[i].value == arr[i + 1].value) {
            arr[i].value = index;
        }
        else
            arr[i].value = index++;
    }
    
    if (arr[num - 1].value != arr[num - 2].value)
        arr[num - 1].value = index++;

    sort(arr.begin(), arr.end(), compare2);

    for (int i = 0; i < num; i++)
        cout << arr[i].value << " ";

    return 0;
}
