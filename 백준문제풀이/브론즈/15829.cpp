#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {

	int num;
	
	cin >> num;
	string str;

	cin >> str;
	int k = 1;

	long long result = 0;

	for (int i = 0; i < num; i++) {
		result += ((str[i] - 'a' + 1) * k) % 1234567891 ;
		k = (k * 31) % 1234567891; 
	}
	
	cout << result % 1234567891;
	
	return 0;
}