#include <iostream>
#include <unordered_map>
#include <stack>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;


int main() {


    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    int num1, num2;

    cin >> num1 >> num2;

    int month = 1;
    int day = 1;
    int result = 1;
    while (true) {
        if (num1 == month && num2 == day)
            break;
        day++;
        result++;

        if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
            if (day == 32) {
                day = 1;
                month++;
            }
        }
        else if (month == 2) {
            if (day == 29) {
                day = 1;
                month++;
            }
        }
        else
            if (day == 31) {
                day = 1;
                month++;
            }


    }

    if (result % 7 == 1)
        cout << "MON";
    else if (result % 7 == 2)
        cout << "TUE";
    else if (result % 7 == 3)
        cout << "WED";
    else if (result % 7 == 4)
        cout << "THU";
    else if (result % 7 == 5)
        cout << "FRI";
    else if (result % 7 == 6)
        cout << "SAT";
    else
        cout << "SUN";

    return 0;


}



