#include <iostream>
#include <unordered_map>
#include <stack>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;


void dfs(vector<int>& arr, vector<bool>& visit, int num1,  int num2, int deep) {

    if (deep == num2) {
        for (int i = 0; i < num2; i++)
            cout << arr[i] << " ";
        cout << '\n';
        return;
    }

    for (int i = 1; i <= num1; i++) {
        if (!visit[i]) {
            visit[i] = 1;
            arr[deep] = i;
            dfs(arr, visit, num1, num2, deep + 1);
            visit[i] = 0;
        }
    }



}




int main() {


    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int num1, num2;

    cin >> num1 >> num2;
    vector <int> arr(num2 + 1);
    vector <bool> visit(num1 + 1);
    
    dfs(arr, visit, num1, num2, 0);

    return 0;


}



