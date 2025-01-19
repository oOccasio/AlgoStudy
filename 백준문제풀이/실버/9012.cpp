#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


class Stack{
private:
	int top;
	char * arr;
	int stack_size;

public:
	Stack(int size = 50) {
		top = -1;
		arr = new char[size];
		fill_n(arr, size, 0);
		stack_size = 0;
	}
	void push(char str) {
		arr[++top] = str;
		stack_size++;
	}
	char pop() {
		stack_size--;
		return arr[top--];
	}
	int size() {
		return stack_size;
	}
};




int main() {


	//Stack 이용없이 품
	/*int num;

	cin >> num;

	vector <string> arr(num);

	cin.ignore();

	string str;
	for (int i = 0; i < num; i++) {
		getline(cin, str);
		arr[i] = str;
		
		int left = 0;
		int right = 0;
		bool Valid = 1;

		for (int j = 0; j < str.size(); j++) {
			
			if (arr[i][j] == '(')
				left++;
			else
				right++;
			if (left < right) {
				Valid = 0;
			}
			if (j == str.size() - 1 && left != right)
				Valid = 0;

		}
		if (Valid == 1)
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';



	}*/


	int num;

	cin >> num;
	Stack s;
	cin.ignore();
	char ch;

	for (int i = 0; i < num; i++) {
		
		while (cin.get(ch)) {
			if (ch == '\n')
				break;
			s.push(ch);
		}
		int right = 0;
		int left = 0;
		bool Valid = 1;


		while (s.size() != 0) {
			if (s.pop() == ')')
				right++;
			else
				left++;
			if (left > right)
				Valid = 0;
			if (s.size() == 0 && left != right)
				Valid = 0;
		}
		if (Valid == 1)
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
	
	}

	


	
	return 0;
}