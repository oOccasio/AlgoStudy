#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {

	int num;
	cin >> num;
	

	int a = 0; 
	int result = 0;
	
	while (true) {
		a++;
		int count = 0;
		for (int i = a; i != 0; i /= 10) {
			if (i % 10 == 6)
				count++;
			else
				count = 0;
			if (count == 3)
				result++;
		}
			
		if (result == num)
			break;
	
	}

	cout << a;

	return 0;
}