#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


int main() {

    int num;

    cin >> num;
    vector <int> arr(num);
    for (int i = 0; i < num; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());

    int result = 0;
    for (int i = 0; i < num; i++)
        result += arr[i] * (num - i);

    cout << result;
    return 0;
}
