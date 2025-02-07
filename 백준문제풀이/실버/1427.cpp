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

    cin >> str;

    vector <int> arr;

    for (int i = 0; i <int(str.size()); i++)
        arr.push_back(str[i] - '0');

    sort(arr.begin(), arr.end(), compare);

    for (int i = 0; i < arr.size(); i++)
        cout << arr[i];
        


    
    return 0;
}
