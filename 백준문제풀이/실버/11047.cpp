#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


int main() {

    int num, result;
    int coin = 0;
    cin >> num >> result;
    vector <int> arr(num);

    for (int i = 0; i < num; i++)
        cin >> arr[i];
    int k = num - 1;
    while (result > 0) {
        if (result >= arr[k]) {
            result -= arr[k];
            coin++;
        }
        else
            k--;

    }

    cout << coin;

    return 0;
}
