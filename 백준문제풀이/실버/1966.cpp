#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct paper
{
	int number;
	int importance;
};

class Que {
private:
	paper* arr;
	int front;
	int rear;
	int qsize;
	bool big;

public:
	Que(int size = 100000) {
		rear = -1;
		front = 0;
		arr = new paper[size];
		qsize = 0;
		big = 1;
	}

	void Push(int num) {
		++rear;
		arr[rear].number = rear;
		arr[rear].importance = num;
		qsize++;
	}
	int Pop() {
		while (true) {
			big = 1;
			for (int i = 0; i < qsize; i++) {
				if (arr[front].importance < arr[front + i].importance) {
					big = 0;
					break;
				}
			}

			if (big == 1) {
				qsize--;
				return arr[front++].number;
			}
			else
				arr[++rear] = arr[front++];

		}

	}
};



int main() {

	int testcase;

	cin >> testcase;

	for (int i = 0; i < testcase; i++) {

		Que q;
		int papers;
		int number;
		int result = 0;
		cin >> papers >> number;

		for (int j = 0; j < papers; j++) {
			int importance;
			cin >> importance;
			q.Push(importance);
		}

		while (true) {
			result++;
			if (q.Pop() == number)
				break;
		}

		cout << result << '\n';

	}



	return 0;
}