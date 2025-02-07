#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;


int main() {


    int number;
    
    cin >> number;

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int dp[50001] = { 0 };
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    
   
    for (int j = 4; j <= number; j++) {
        int length = sqrt(j);
        int minnum = j;

        for (int i = 2; i <= length; i++) {
            int re;
            if (j % (i * i) == 0)
                minnum = min(minnum, j / (i * i));
            else {
                re = j % (i * i);
                minnum = min(minnum, dp[re] + j/ (i*i));
            }
            
        }
        dp[j] = minnum;

    }
    cout << dp[number];

    return 0;
}