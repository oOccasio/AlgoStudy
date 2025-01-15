#include <iostream>
#include <vector>
#include <string>

using namespace std;



int main() {

	int num = 0;
	string str;


	while (true) {
	
		cin >> str;
		int length = str.size();
		bool pel = 1;

		if (str[0] == '0' && length == 1)
			break;
		
		for (int i = 0; i < length/2; i++) {
			if (str[i] != str[length - i - 1])
				pel = 0;
		}

		if (pel == 1)
			cout << "yes" << '\n';
		else
			cout << "no" << '\n';

	}
	return 0;
}