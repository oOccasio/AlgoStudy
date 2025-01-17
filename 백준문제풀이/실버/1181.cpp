#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool compare(string a, string b) {
	if (a.length() == b.length())
		return a < b;
	else
		return a.length() < b.length();
}


int main() {

	int num;

	cin >> num;

	string arr[20001];


	for (int i = 0; i < num; i++) {
		cin >> arr[i];
	}

	//abc ab a 

	sort(arr, arr + num, compare);
	
	cout << arr[0] << '\n';
	for (int i = 1; i < num; i++) {
		if (arr[i] == arr[i - 1])
			continue;
		cout << arr[i] << '\n';
	}

	

	return 0;
}