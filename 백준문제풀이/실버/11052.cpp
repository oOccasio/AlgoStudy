#include <iostream>
#include <set>
#include<vector>
#include<queue>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int num;
    cin >> num;
    vector <int> arr(num + 1);
    vector <int> dp(num + 1);

    for (int i = 1; i <= num; i++)
        cin >> arr[i];

    
    dp[1] = arr[1];
    int maxnum;
    for (int i = 2; i <= num; i++) {
        maxnum = arr[i];
        for (int j = 1; j <= i / 2; j++) {
            
            maxnum = max(maxnum, dp[i - j] + dp[j]);
        }
        dp[i] = maxnum;

    }   

    cout << dp[num];

}
