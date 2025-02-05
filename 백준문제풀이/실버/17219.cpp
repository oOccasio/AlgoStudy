#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;




int main() {


    unordered_map<string, string> um;

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int number, result;
    cin >> number >> result;
    string domain, password;

    for (int i = 0; i < number; i++) {
        cin >> domain >> password;
        um[domain] = password;
    }

    for (int i = 0; i < result; i++) {
        cin >> domain;
        cout << um[domain] << '\n';
    }
        
    return 0;
}
