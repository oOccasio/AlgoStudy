#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int Zero(int num) {
	int zero = 0;
	
	while (true) {
		if (num % 5 == 0) {
			num /= 5;
			zero++;
		}
		if (num % 5 != 0)
			break;
	}
	return zero;
	
}


int main() {

	int num;
	int count = 0;
	cin >> num;
	
	for (int i = 1; i <= num; i++) {
		
		count += Zero(i);

	}

	cout << count;



	return 0;
}