#include <iostream>
#include <unordered_map>
#include <stack>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;




int main() {

    int p, num;
    cin >> p >> num;
    int result = 0;

    vector <char> arr(num);

    for (int i = 0; i < num; i++)
        cin >> arr[i];

    queue<char> q;

    for (int i = 0; i < num; i++) {

        if (q.size() % 2 == 0)
            if (arr[i] == 'I')
                q.push(arr[i]);
            else
                while (!q.empty())
                    q.pop();
        else {
            if (arr[i] == 'O')
                q.push(arr[i]);
            else {
                while (!q.empty())
                    q.pop();
                q.push(arr[i]);
            }
        }
        if (q.size() == 2 * p + 1) {
            result++;
            q.pop();
            q.pop();
            
        }
    }



    cout << result;
    return 0;
}



