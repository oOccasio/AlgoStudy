#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <stack>

using namespace std;




int main() {



    int testcase;

    cin >> testcase;
    int dp[11] = { 0 };

    dp[1] = 1;
    dp[2] = 1;
    for (int i = 0; i < testcase; i++) {
        int number;
        cin >> number;
        for (int j = 3; j <= number; j++) {
            dp[j] = dp[j-2] + dp[j - 1] + j;
        }
        cout << dp[number] << '\n';
    }
    

    return 0;
}
