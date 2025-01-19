#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {


	int num1;
	
	cin >> num1;

	vector <int> arr(num1);

	for (int i = 0; i < num1; i++)
		cin >> arr[i];

	sort(arr.begin(), arr.end());
	int num2;

	cin >> num2;


	int number;
	for (int i = 0; i < num2; i++) {
		cin >> number;

		cout << upper_bound(arr.begin(), arr.end(), number) - lower_bound(arr.begin(), arr.end(), number) << ' ';
		
	}



	return 0;
}