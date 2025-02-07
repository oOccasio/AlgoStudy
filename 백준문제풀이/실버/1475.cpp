#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <stack>
#include <queue>
using namespace std;


bool compare(int a, int b) {
    return a > b;
}

int main() {


    string str;
    int arr[10] = { 0 };

    cin >> str;

    for (int i = 0; i < str.size(); i++)
        arr[str[i] - '0']++;

    arr[9] = (arr[6] + arr[9]) / 2 + (arr[6] + arr[9]) % 2;
    arr[6] = arr[9];
    int maxnum = 0;
    for (int i = 0; i < 10; i++) {
        maxnum = max(maxnum, arr[i]);
    }
    cout << maxnum;


    return 0;
}
