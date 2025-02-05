#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;




int main() {

    int number;
    cin >> number;

    vector <int> arr(number + 1);

    if (number == 2)
        cout << 1;
    else if (number == 3)
        cout << 1;
    else {

        arr[2] = 1;
        arr[3] = 1;

        for (int j = 4; j < number + 1; j++) {
            if (j % 2 == 0 && j % 3 == 0)
                arr[j] = min(min(arr[j / 2], arr[j - 1]), arr[j / 3]) + 1;
            else if (j % 2 == 0)
                arr[j] = min(arr[j / 2], arr[j - 1]) + 1;
            else if (j % 3 == 0)
                arr[j] = min(arr[j / 3], arr[j - 1]) + 1;
            else
                arr[j] = arr[j - 1] + 1;
        }
        cout << arr[number];
    }
    


    return 0;
}
