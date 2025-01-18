#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct coordinate {
	int x;
	int y;
};

int errorcheck(char chess[8][8]) {

	int error1 = 0;
	int error2 = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (i % 2 == 0)
				if (j % 2 == 0) {
					if (chess[i][j] != 'W')
						error1++;
				}
				else {
					if (chess[i][j] != 'B')
						error1++;
				}
			else
				if (j % 2 == 0) {
					if (chess[i][j] != 'B')
						error1++;
				}
				else {
					if (chess[i][j] != 'W')
						error1++;
				}
		}
	}

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (i % 2 == 0)
				if (j % 2 == 0) {
					if (chess[i][j] != 'B')
						error2++;
				}
				else {
					if (chess[i][j] != 'W')
						error2++;
				}
			else
				if (j % 2 == 0) {
					if (chess[i][j] != 'W')
						error2++;
				}
				else {
					if (chess[i][j] != 'B')
						error2++;
				}
		}
	}
	if (error1 < error2)
	{
		return error1;
	}
	else
		return error2;
}




int main() {

	int x, y;

	cin >> x >> y;
	
	char arr[50][50];
	char chess[8][8];
	int error = 64;

	for (int i = 0; i < x; i++)
		for (int j = 0; j < y; j++)
			cin >> arr[i][j];

	int try1 = 0;
	int try2 = 0;
	int a = 0;
	int b = 0;
	while(try1 != x - 7 && try2 != y - 7){
		a = try1;
		b = try2;
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				chess[i][j] = arr[a][b];
				b++;
				if (j == 7)
					b = try2;
			}
			a++;
		}
		if (errorcheck(chess) < error)
			error = errorcheck(chess);
		if (try2 == y - 8) {
			try2 = 0;
			try1++;
		}
		else
			try2++;

	}
	cout << error;

	
	

	return 0;
}