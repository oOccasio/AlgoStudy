#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {

	int num;

	cin >> num;

	int count = 1;

	int a = 0;
	int b = 1;

	while (true) {
		if (a <= num && num <= b)
			break;
		a += (count - 1) * 6;
		b = b + count * 6;
		count++;

	}

	cout << count; 

	return 0;
}