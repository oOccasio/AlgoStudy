#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;




int main() {

    int number;
    cin >> number;

    vector <int> score(number + 1);
    long long dp[301] = { 0 };

    for (int i = 1; i <= number; i++)
        cin >> score[i];

    dp[1] = score[1];


    if (number >= 2) {
        dp[2] = score[1] + score[2];
        for (int j = 3; j <= number; j++) {

            dp[j] = max(dp[j - 2] + score[j], dp[j - 3] + score[j - 1] + score[j]);
        }
    }


    cout << dp[number];
    return 0;
}
