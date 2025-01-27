#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {

	int num;

	cin >> num;
	if (num == 0) {
		cout << 0;
		return 0;
	}

	vector<int> arr(num);
	
	for (int i = 0; i < num; i++)
		cin >> arr[i];

	float mean;

	mean  = num * 0.15 + 0.5;

	sort(arr.begin(), arr.end());
	
	float result = 0;
	int length = num - (2 * int(mean));

	for (int i = 0 + int(mean); i < num - int(mean); i++)
		result += arr[i];

	cout << int (result/length + 0.5);


	return 0;
}