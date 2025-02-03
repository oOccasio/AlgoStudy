#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Stack {
private:
	int* arr;
	int top;
	int size;
	char * arr2;
	int index;
	int size2;
public:
	Stack(int size = 100001) {
		top = -1;
		size = 0;
		arr = new int[size];
		arr2 = new char[200002];
		index = 0;
		size2 = 0;
	}
	void Push(int num) {
		arr[++top] = num;
		size++;
		arr2[index++] = '+';
		size2++;
	}
	bool empty() {
		return size == 0;
	}

	void Pop() {
		arr[top--];
		arr2[index++] = '-';
		size--;
		size2++;
	}
	
	int gettop() {
		return arr[top];
	}
	void Result() {
		for (int i = 0; i < size2; i++)
			cout << arr2[i] << '\n';
	}
};

int main() {

	int num;

	bool flag = 1;
	cin >> num;
	Stack s;
	int max = 0;

	int number;
	for (int i = 0; i < num; i++) {
		cin >> number;
		
		if (max < number) {
			for (int j = max + 1; j <= number; j++)
				s.Push(j);
			max = s.gettop();
			}				
		else if (s.gettop() == number) {
			s.Pop();
			continue;
		}
		else {
			flag = 0;
			break;
		}
		
		s.Pop();
	}
	if (flag)
		s.Result();
	else
		cout << "NO";


	return 0;
}