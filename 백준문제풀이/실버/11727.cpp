#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


int main() {


    int number;
    
    cin >> number;

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int dp[1001] = { 0 };
    dp[1] = 1;
    dp[2] = 3;
    


    for (int i = 3; i <= number; i++)
        dp[i] = ((dp[i - 1] + dp[i-2] * 2)) % 10007;

    cout << dp[number];

    return 0;
}