#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;




int main() {

    int number;
    cin >> number;

    int count = 0;

    while(number > 0) {
        if (number % 2 == 1)
            count++;
        number /= 2;
    }
    cout << count;

    return 0;
}
