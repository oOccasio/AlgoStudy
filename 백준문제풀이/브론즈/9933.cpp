#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string pelin(string str) {
	char tmp;

	for (int i = 0; i < str.size() / 2; i++) {
		tmp = str[i];
		str[i] = str[str.size() - 1 - i];
		str[str.size() - 1 - i] = tmp;
	}

	return str;
}



int main() {

	int num;

	cin >> num;

	string str; 
	vector <string> arr(num);

	for (int i = 0; i < num; i++) {
		cin >> arr[i]; 
	}

	for (int i = 0; i < num; i++) {
		str = pelin(arr[i]);

		for (int j = 0; j < num; j++)
			if (str == arr[j]) {
				cout << str.size() << ' ' << str[(str.size() - 1) / 2];
				return 0;
			}
	}


	return 0;
}