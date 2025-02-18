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

    int tc;
    cin >> tc;
    int num1, num2, num3, num4;

    while (tc--) {

        cin >> num1 >> num2 >> num3 >> num4;

        if (num1 < num2) {
            swap(num1, num2);
            swap(num3, num4);
        }

        if (num2 == num4)
            num4 = 0;
        if (num1 == num3)
            num3 = 0;

        int result = 0;
        
        for (int i = num3; i <= num1 * num2; i += num1)
            if (i != 0 && i % num2 == num4) {
                    result = i;
                    break;
             }
        
        

        if (result != 0)
            cout << result << '\n';
        else
            cout << -1 << '\n';




    }

    return 0;
}



