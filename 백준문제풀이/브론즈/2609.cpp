#include <iostream>
#include <vector>
#include <string>

using namespace std;



int main() {

	int x,y;
	cin >> x >> y;
	


	//유클리드 호제법
	int a, b, tmp;
	a = x;
	b = y;
	
		
	while (a % b != 0) {
		tmp = b;
		b = a % b;
		a = tmp;
	}

	cout << b << "\n" << x * y / b;

	
	// 약수방법
	/*
	int max = 1;

	for (int i = 1; i <= x && i <= y; i++) {
		if (x % i == 0 && y % i == 0)
			if (max < i)
				max = i;
	}

	

	cout << max << "\n" << x * y / max;

	*/


	return 0;
}