#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


int main() {



    int testcase;
    long long dp[101] = { 0 };


    cin >> testcase;

    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    dp[4] = 2;
    
    
    int number; 
    
    for (int i = 0; i < testcase; i++) {

        cin >> number;

        for (int j = 5; j <= number; j++) {
            dp[j] = dp[j - 5] + dp[j - 1];
        }

        cout << dp[number] << '\n';

    }




    return 0;
}