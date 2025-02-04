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

	cout << arr[0] << " ";
	for (int i = 1; i < num; i++) {
		if (arr[i] == arr[i - 1])
			continue;
		else
			cout << arr[i] << " ";

	}
	
		
	return 0;
}