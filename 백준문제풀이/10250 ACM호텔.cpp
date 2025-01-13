#include <iostream>
using namespace std;

int main() {

	int test;
	cin >> test;
	int w, h, guest;
	int num1, num2 = 0;
	int result;

	for (int i = 0; i < test; i++) {

		cin >> h >> w >> guest;

		if (h == 1)
			result = 100 + guest;
		else if (w == 1) {
			result = 100 * guest + 1;
		}
		else {
			num1 = guest / h;
			num2 = guest % h;
			if (num2 == 0) {
				num2 = h;
				num1--;
			}

			result = num2 * 100 + num1 + 1;
			
		}
		cout << result << endl;


	}
	


}
