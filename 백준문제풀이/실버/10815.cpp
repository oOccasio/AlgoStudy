#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int Search(vector <int> &arr, int key, int num) {
	int low = 0;
	int high = num - 1;

	while (low <= high) {
		int mid = (high + low) / 2;

		if (arr[mid] == key)
			return 1;
		else if (arr[mid] < key)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return 0;

}




int main() {


	int num;
	int card;

	cin >> num;
	vector <int> arr(num);

	for (int i = 0; i < num; i++)
		cin >> arr[i];

	cin >> card;

	vector <int> arr2(card);

	for (int i = 0; i < card; i++)
		cin >> arr2[i];

	sort(arr.begin(), arr.end());

	for (int i = 0; i < card; i++) {
		cout << Search(arr, arr2[i], num) << " ";
	}



	return 0;
}