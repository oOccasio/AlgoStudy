#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {

	int day = 0;
	int up;
	int down;
	int tree;
	int height = 0;

	cin >> up >> down >> tree;

	tree -= up;
	
	day = tree / (up - down);
	
	if (tree % (up - down) == 0)
		cout << day + 1;
	else
		cout << day + 2;

	return 0;
}