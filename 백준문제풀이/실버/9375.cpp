#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <stack>

using namespace std;


int main() {



    int testcase;
   

    cin >> testcase;

    for (int i = 0; i < testcase; i++) {
        int number;
        int result = 1;
        cin >> number;

        unordered_map <string, vector<string>> closet;

        vector <string> arr;
        string str1, str2;
        for (int j = 0; j < number; j++) {
            cin >> str1 >> str2;
            if (closet.find(str2) == closet.end())
                arr.push_back(str2);
            closet[str2].push_back(str1);
        }
        
        
        int length = arr.size();
        
        
        vector <int> NumArr(length);

        for (int j = 0; j < length; j++)
            NumArr[j] = closet[arr[j]].size();
     
        for (int j = 0; j < length; j++)
            result *= (NumArr[j] + 1);
        cout << result - 1 << '\n';
        
        
    }

    return 0;
}