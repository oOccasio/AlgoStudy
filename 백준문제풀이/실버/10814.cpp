#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct info {
	int age;
	string name;
	int number;
};



bool compare(info a, info b) {
	if (a.age != b.age)
		return a.age < b.age;
	else
		return a.number < b.number;
}


int main() {

	int num;

	cin >> num;

	vector<info> arr(num);

	for (int i = 0; i < num; i++) {
		cin >> arr[i].age >> arr[i].name;
		arr[i].number = i;
	}

	
	sort(arr.begin(), arr.end(), compare);
	
	for (int i = 0; i < num; i++) {
		cout << arr[i].age << ' ' << arr[i].name << "\n";
	}

	

	return 0;
}