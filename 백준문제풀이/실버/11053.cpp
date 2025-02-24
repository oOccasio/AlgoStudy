#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int num;

    cin >> num;

    vector <int> arr(num + 1);
    vector <int> dp(num + 1);
    for (int i = 1; i <=num; i++)
        cin >> arr[i];

    dp[1] = 1;
    for (int i = 2; i <= num; i++) {
        for (int j = 1; j < i; j++) {
            if (arr[i] > arr[j])
                dp[i] = max(dp[i], dp[j] + 1);
        }
        if (dp[i] == 0)
            dp[i] = 1;
    
    
    
    }
    int result = 0;
    
    for (int i = 1; i <= num; i++)
        result = max(result, dp[i]);

    
    
    cout << result;

    return 0;
}
