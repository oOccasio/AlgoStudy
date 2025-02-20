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



    int a, b, c;

    int dp[21][21][21] = { 0 };

    int num1, num2, num3;


    for (int i = 0; i < 21; i++)
        for (int j = 0; j < 21; j++)
            for (int k = 0; k < 21; k++) {

                if (i == 0 || j == 0 || k == 0) {
                    dp[i][j][k] = 1;
                    continue;
                }

                if (i - 1 < 0)
                    num1 = 0;
                else
                    num1 = i - 1;
                if (j - 1 < 0)
                    num2 = 0;
                else
                    num2 = j - 1;
                if (k - 1 < 0)
                    num3 = 0;
                else
                    num3 = k - 1;
                if (i < j && j < k)
                    dp[i][j][k] = dp[i][j][num3] + dp[i][num2][num3] - dp[i][num2][k];

                else
                    dp[i][j][k] = dp[num1][j][k] + dp[num1][num2][k] + dp[num1][j][num3] - dp[num1][num2][num3];

            }
    int result; 
    while (true) {

        cin >> a >> b >> c;

        if (a == -1 && b == -1 && c == -1)
            break;
        if (a <= 0 || b <= 0 || c <= 0) {
            result = 1;
        }
        else if (a > 20 || b > 20 || c > 20)
            result = dp[20][20][20];
        else
            result = dp[a][b][c];


        cout << "w(" << a << ", " << b << ", " << c << ")" << " = " << result << '\n';


    }

    return 0;


}



