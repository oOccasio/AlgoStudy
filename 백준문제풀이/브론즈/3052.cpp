#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {

	int result = 0;
	int arr[10][2] = {0};

	for (int i = 0; i < 10; i++)
		cin >> arr[i][0];

	for (int i = 0; i < 10; i++)
		arr[i][0] = arr[i][0] % 42;

	for (int i = 0; i < 10; i++) {
		for (int j = i; j < 10 ; j++) {
			if (arr[i][1] == 0)
				result++;			
			if (arr[i][0] == arr[j][0])
				arr[j][1] = 1;
			
		}
	}

	cout << result;

	return 0;
}