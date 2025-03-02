#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int arr[100001];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    vector<int> dp(n + 1);

    dp[1] = arr[1];

    for (int i = 2; i <= n; i++) {
        dp[i] = max(dp[i - 1] + arr[i], arr[i]);
    }

    int result = -1001;

    for (int i = 1; i <= n; i++)
        result = max(result, dp[i]);

    cout << result;
   
    return 0;
}
