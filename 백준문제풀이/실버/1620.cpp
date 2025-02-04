#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;




int main() {

    unordered_map<string, int> StringToNum;
    unordered_map<int, string> NumToString;
    int num, number;


    cin.tie(0); 
    ios::sync_with_stdio(0);

    cin >> num >> number;
    string str;
    for (int i = 0; i < num; i++) {
        cin >> str;
        StringToNum[str] = i + 1;
        NumToString[i + 1] = str;
    }

    int result;
    for (int i = 0; i < number; i++) {
        cin >> str;

        if (str[0] >= '0' && str[0] <= '9') {
            result = stoi(str);
            cout << NumToString[result] << '\n';
        }
        else
            cout << StringToNum[str] << '\n';

    }
    
    return 0;
}
