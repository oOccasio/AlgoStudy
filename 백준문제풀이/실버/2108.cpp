#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;



int main() {

	int num;
	double result = 0;
	int min, max;

	cin >> num;

	int freq[8001] = { 0 };
	vector <int> arr(num);


	for (int i = 0; i < num; i++) {
		cin >> arr[i];
		if (arr[i] < 0)
			freq[4000 - arr[i]]++;
		else
			freq[arr[i]]++;
	}

	for (int i = 0; i < num; i++) {
		result += arr[i];
	}
	if (result > 0)
		cout << int(result / num + 0.5) << '\n';
	else if (result == 0)
		cout << 0 << '\n';
	else
		cout << int(result / num + -0.5) << '\n';


	sort(arr.begin(), arr.end());

	cout << arr[num / 2] << '\n';

	max = 0;
	int check = 0;
	for (int i = 0; i < 8001; i++)
		if (max < freq[i])
			max = freq[i];

	for (int i = 8000; i > 4000; i--) {
		if (max == freq[i]) {
			check++;
			result = i;
		}
		if (check == 2) {
			result = i;
			break;
		}
	}
	if (check == 2)
		cout << (4000 - result)  << '\n';

	else
	{
		for (int i = 0; i < 4001; i++) {

			if (max == freq[i]) {
				check++;
				result = i;
			}
			if (check == 2) {
				break;
			}
		}
		if (result > 4000)
			cout << 4000 - result << '\n';
		else
			cout << result << '\n';


	}
	
	min = arr[0];
	max = arr[num - 1];

	cout << max - min;



	return 0;
}