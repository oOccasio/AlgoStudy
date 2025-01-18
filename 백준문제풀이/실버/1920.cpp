#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


int Search(vector<int> &arr, int key, int length) {

	int low = 0;
	int mid;
	int high = length - 1;
	while (low <= high) {
		mid = (low + high)/2;
		if (key == arr[mid])
			return 1;
		else if (key > arr[mid])
			low = mid + 1;
		else
			high = mid - 1;

	}
	return 0;
}


int main() {

	int num1;
	
	cin >> num1;

	vector <int> arr1(num1);
	
	for (int i = 0; i < num1; i++)
		cin >> arr1[i];

	int num2;

	cin >> num2;

	vector <int> arr2(num2);

	
	
	for (int i = 0; i < num2; i++)
		cin >> arr2[i];

	sort(arr1.begin(), arr1.end());

	for (int i = 0; i < num2; i++)
		cout << Search(arr1, arr2[i], num1)<< '\n';

		

	return 0;
}