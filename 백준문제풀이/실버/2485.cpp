#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


int min(int num1, int num2) {
	int tmp;
	
	while (true) {
		if (num2 % num1 == 0)
			return num1;
		else {
			tmp = num1;
			num1 = num2 % num1;
			num2 = tmp;
		}
	}
}





int main() {

	int num;

	cin >> num;

	vector <int> arr(num);
	vector <int> minus(num-1);
	int result = 0;
	for (int i = 0; i < num; i++) 
		cin >> arr[i];
	
	
	
	for (int i = 1; i < num; i++)
		minus[i - 1] = arr[i] - arr[i - 1];

	sort(minus.begin(), minus.end());

	int div = min(minus[0], minus[1]);

	for (int i = 2; i < num - 1; i++)
		if (div > min(minus[0], minus[i]))
			div = min(minus[0], minus[i]);


	for (int i = 0; i < num - 1; i++) {
		if (div == minus[i])
			continue;
		else
			result += minus[i] / div - 1;
			
	}


	cout << result;
	

	return 0;
}