#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <stack>
#include <queue>
using namespace std;


int main() {


    string str;

    cin >> str;
    int result = 0;
    vector <int> arr; 
    int number = 0;
    int minus = 0;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] >= '0' && str[i] <= '9')
            number = number * 10 + (str[i] - '0');
        else {
            arr.push_back(number);
            number = 0;
            if (str[i] == '-') {
                arr.push_back(-1);
                minus++;
            }
        }
        if (i == str.size() - 1)
            arr.push_back(number);

    }

    vector <int> sum(minus);
    int index = -1;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == -1) {
            index++;
            continue;
        }
        if (index >= 0)
            sum[index] += arr[i];

        else
            result += arr[i];
    }
    for (int i = 0; i < minus; i++)
        result -= sum[i];


    cout << result;

    return 0;
}
