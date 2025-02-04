#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;






int main() {

	int num;

	cin >> num;

	vector <int> arr(num);

	for (int i = 0; i < num; i++)
		cin >> arr[i];
	
	sort(arr.begin(), arr.end());

	if (num % 2 == 0) {
		cout << arr[0] * arr[num - 1];
	}
	else
		cout << arr[num / 2] * arr[num / 2];


	return 0;
}