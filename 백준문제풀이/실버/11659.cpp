#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


int main() {


    int number;
    int testcase;
    int num1, num2;

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> number >> testcase;
    vector <int> arr(number + 1);
    vector <long long> dp(number + 1);

    for (int i = 1; i <= number; i++) {
        cin >> arr[i];
        dp[i] = dp[i - 1] + arr[i];

    }
    
    

    for (int i = 0; i < testcase; i++) {

        cin >> num1 >> num2;

        cout << dp[num2] - dp[num1 - 1] << '\n';
    }


    return 0;
}