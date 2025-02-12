#include <iostream>
#include <unordered_map>
#include <stack>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;




int main() {


    unordered_map <string, int> arr;

    int num1, num2;

    cin >> num1 >> num2;

    string str;
    for (int i = 0; i < num1; i++) {
        cin >> str;
        arr[str] = 1;

    }
    int result = 0;

    for (int i = 0; i < num2; i++) {
        cin >> str;
        if (arr.find(str) != arr.end())
            result++;
    }

    cout << result; 

    return 0;
}



