#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int fizzbuzz(int num) {
	if (num % 3 == 0 && num % 5 == 0)
		return 1;
	else if (num % 3 == 0 && num % 5 != 0)
		return 2;
	else if (num % 3 != 0 && num % 5 == 0)
		return 3;
	else
		return 4;
}


int main() {

	string str;
	int num;
	int result;
	for (int i = 0; i < 3; i++){
		cin >> str;

		if ('0' <= str[0] && str[0] <= '9') {
			num = stoi(str);
			num += 3 - i;
			result = fizzbuzz(num);			
			break;
		}
			
	}

	if (result == 1)
		cout << "FizzBuzz";
	else if (result == 2)
		cout << "Fizz";
	else if (result == 3)
		cout << "Buzz";
	else
		cout << num;
	

	return 0;
}