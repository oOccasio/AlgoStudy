#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int Search(vector <int> arr, int num, int number) {
	long long low = 1;
	long long high = arr[num - 1];
	long long ret;

	while (low <= high) {
		long long mid = (low + high) / 2;
		int result = 0;
		for (int i = 0; i < num; i++)
			result +=  arr[i] / mid;
		if (result >= number) {
			low = mid + 1;
			ret = mid;
		}
		else {
			high = mid - 1;
		}
	}
	
	return ret;
}


int main() {

	int num;
	int number;
	int result;

	cin >> num >> number;

	vector <int> arr(num);


	for (int i = 0; i < num; i++)
		cin >> arr[i];

	sort(arr.begin(), arr.end());

	cout << Search(arr, num, number);
	

	return 0;
}