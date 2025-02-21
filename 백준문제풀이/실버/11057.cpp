#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {

	int num;

	cin >> num;

	int dp[1001][10] = { 0 };
	int sum[1001] = { 0 };
	int number = 10;
	int result = 0;
	
	if (num >= 2) {
		for (int i = 0; i < 10; i++) {
			dp[2][i] = number--;

		}

		for (int i = 0; i < 10; i++)
			sum[2] += dp[2][i];

		for (int i = 3; i <= num; i++) {
			result = 0;
			for (int j = 9; j >= 0; j--) {
				result = (result+ dp[i - 1][j]) % 10007;
				dp[i][j] = result;

			}
			for (int j = 0; j < 10; j++) {
				sum[i] = (sum[i] + dp[i][j]) % 10007;
			}
		}
	}
	else
		sum[1] = 10;

	cout << sum[num];



	return 0;
}