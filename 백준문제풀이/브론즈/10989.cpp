#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {

	int num;

	cin >> num;

	int arr[10001] = { 0 };

	int number;
	for (int i = 0; i < num; i++) {
		cin >> number;
		arr[number]++;
	}
		

	
	for (int i = 0; i <= 10000; i++) {
		for (int j = arr[i]; j > 0; j--)
				cout << i << '\n';
	}

	return 0;
}