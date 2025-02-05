#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


struct ZeroOne {
    int Zero;
    int One;
};



int main() {

    int num;

    cin >> num;

    ZeroOne fib[41] = { 0 };
    
    fib[0].Zero = 1;
    fib[1].One = 1;

    for (int i = 0; i < num; i++) {
        int number;
        cin >> number;
        if (number == 0)
            cout << '1' << " " << "0" << '\n';
        else if (number == 1)
            cout << '0' << " " << "1" << '\n';
        else {
            for (int j = 2; j <= number; j++) {
                fib[j].One = fib[j - 1].One + fib[j - 2].One;
                fib[j].Zero = fib[j - 1].Zero + fib[j - 2].Zero;
            }
            cout << fib[number].Zero << " " << fib[number].One << '\n';
        }

    
    }

    
    return 0;
}
