#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {

	int num;
	bool Valid = 0;
	cin >> num;

	int arr[7] = { 0 };

	
	for (int i = 0; i < num; i++) {
		

		int result = i;

		int a = 0;
		for (int j = i; j > 0; j /= 10) {
			arr[a++] = j % 10;
		}

		for (int k = 0; k < 7; k++) {
			result += arr[k];
		}
		if (result == num) {
			cout << i;
			Valid = 1; 
			break;
		}

	}

	if (Valid == 0)
		cout << 0;

	return 0;
}