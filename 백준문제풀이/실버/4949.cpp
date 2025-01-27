#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


class Stack {
private:
	int top;
	char * arr;
	int stack_size;

public:
	Stack(int size = 101) {
		top = -1;
		arr = new char[size];
		stack_size = 0;
	}
	void Push(char ch) {
		arr[++top] = ch;
		stack_size++;
	}
	char Pop() {
		if (stack_size == 0)
			return 0;
		stack_size--;
		return arr[top--];

	}
	int size(){
		return stack_size;
	}
	char Peek() {
		return arr[top];
	}

};


int main() {

	

	string str;

	while (true) {
		
		getline(cin, str);
		Stack s1;
		
		if (str == ".")
			break;
			
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == '(')
				s1.Push(str[i]);
			if (str[i] == ')') {
				char popped = s1.Pop();
				if (popped != '(' || popped == 0) {
					cout << "no" << '\n';
					break;
				}
			}
				
			if (str[i] == '[')
				s1.Push(str[i]);
			if (str[i] == ']') {
				char popped = s1.Pop();
				if (popped != '[' || popped == 0) {
					cout << "no" << '\n';
					break;
				}
			}
			if (i == str.size() - 1)
				if (s1.size() == 0)
					cout << "yes" << '\n';
				else
					cout << "no" << '\n';
		
		}


	}


	return 0;
}