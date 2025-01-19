#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;



int main() {


	int num;

	cin >> num;

	int arr[100000] = { 0 };
	int size = 0;
	int front = 0;
	int back = -1;
	


	for (int i = 0; i < num; i++) {
		string str;
		cin >> str;

		if (str == "push") {
			int num;
			cin >> num;
			arr[++back] = num;
			size++;
		}
	
		if (str == "pop") {
			if (size == 0)
				cout << -1 << '\n';
			else {
				cout << arr[front++] << '\n';
				size--;
			}
		}


		if (str == "size")
			cout << size << '\n';

		if(str == "empty"){
			if(size == 0)
				cout << 1 << '\n';
			else 
				cout << 0 << '\n';
		}

		if (str == "front") {
			if (size == 0)
				cout << -1 << "\n";
			else 
				cout << arr[front] << '\n';
		}
		if (str == "back") {
			if (size == 0)
				cout << -1 << '\n';
			else
				cout << arr[back] << '\n';
		}
	
	}

	
	return 0;
}