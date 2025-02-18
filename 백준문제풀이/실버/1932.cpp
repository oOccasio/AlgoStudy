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

    int arr[500][500] = { 0 };

    for (int i = 0; i < num; i++) {
        for (int j = 0; j <= i; j++)
            cin >> arr[i][j];
    }

    int dp[500][500] = {0};

    dp[0][0] = arr[0][0];
    
    for (int i = 1; i < num; i++) {
        for (int j = 0; j <=i; j++) {
         
            if (j == 0)
                dp[i][j] = dp[i - 1][j] + arr[i][j];
            else if (j == i)
                dp[i][j] = dp[i - 1][j - 1] + arr[i][j];
            else
                dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + arr[i][j];


        }
    }

    int result = 0;
    for (int i = 0; i < num; i++)
        result = max(result, dp[num - 1][i]);
    cout << result;

    return 0;


}



