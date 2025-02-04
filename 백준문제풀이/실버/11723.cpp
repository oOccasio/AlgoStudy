#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int num;
    cin >> num;
    int arr[21] = { 0 };

    while (num--) {
        string str;
        int x;

        cin >> str;
        if (str == "add") {
            cin >> x;
            arr[x] = 1;
        }
        else if (str == "remove") {
            cin >> x;
            arr[x] = 0;
        }
        else if (str == "check") {
            cin >> x;
            cout << arr[x] << '\n';
        }
        else if (str == "toggle") {
            cin >> x;
            arr[x] = 1 - arr[x];  
        }
        else if (str == "all") {
            fill(arr, arr + 21, 1);
        }
        else {
            fill(arr, arr + 21, 0);
        }
    }

    return 0;
}
