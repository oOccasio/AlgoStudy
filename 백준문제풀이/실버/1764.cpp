#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;


int main() {

    map<string, int> StringToNum;
    int num, number;
    cin.tie(0); 
    ios::sync_with_stdio(0);

    cin >> num >> number;

    vector <string> arr;
    string str;
    
    for (int i = 0; i < num; i++) {
        cin >> str;
        StringToNum[str] = i;
    }

    for (int i = 0; i < number; i++) {
        cin >> str;

        if (StringToNum.find(str) != StringToNum.end())
            arr.push_back(str);
    }
    
    
    sort(arr.begin(), arr.end());
    cout << arr.size() << '\n';
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << '\n';
    }

    return 0;
}
