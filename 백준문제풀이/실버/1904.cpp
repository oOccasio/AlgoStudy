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


    int num;
    cin >> num;

    int dp[1000000] = { 0 };
    

    dp[1] = 1;
    if (num >= 2)
        dp[2] = 2;

    if (num >= 3)
        dp[3] = 3;

    for (int j = 4; j <= num; j++)
        dp[j] = dp[j - 2] + dp[j - 1] % 15746;


    cout << dp[num];

    return 0;


}



