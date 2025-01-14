#include <iostream>
#include <vector>
#include <string>

using namespace std;

int dec(int a) {
	if (a == 1)
		return 0;
	for (int i = 2; i <= 1000; i++) {
		if (a % i == 0)
			if (a == i)
				continue;
			else
				return 0;

	}
	return 1;

}


int main() {

	int num;
	cin >> num;
	int result = 0;

	for (int i = 0; i < num; i++) {
		int a;
		cin >> a;
		result += dec(a);

	}
	cout << result;

	return 0;
}