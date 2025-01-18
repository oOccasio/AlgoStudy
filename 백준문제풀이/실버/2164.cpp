#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


class Queue
{
private:
	int rear;
	int front;
	int * arr;
	int q_size;

public:
	Queue(int size = 1000000){
		q_size = 0;
		rear = -1;
		front = 0;
		arr = new int[size];
		fill_n(arr, size, 0);
		}

	~Queue() {
		delete[] arr;
	}
	void Insert(int num) {
		arr[++rear] = num;
		q_size++;
	}
	void Delete() {
		arr[front++];
		arr[++rear] = arr[front++];
		q_size--;
	}
	
	int size() {
		return q_size;
	}
	
	void Peek() {
		cout << arr[rear];
	}

};



int main() {

	int num;

	cin >> num;

	
	Queue q;

	for (int i = 0; i < num; i++)
		q.Insert(i + 1);

	for (int i = 0 ; i < num - 1; i++)
		q.Delete();

	q.Peek();


	return 0;
}