#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int maxnum = 0;


void maxtet2(vector<vector <int>>& arr, int num1, int num2, int starti, int startj) {

    int value = arr[starti][startj];
    int value1, value2, value3, value4; 
    if (starti - 1 >= 0) {
        value1 = arr[starti - 1][startj];
    }
    else
        value1 = 0;

    if (starti + 1 < num1) {
        value2 = arr[starti + 1][startj];

    }
    else
        value2 = 0;
    if (startj - 1 >= 0) {
        value3 = arr[starti][startj - 1];
    }
    else
        value3 = 0;
    if (startj + 1 < num2) {
        value4 = arr[starti][startj + 1];
    }
    else
        value4 = 0;

    maxnum = max(maxnum, value + value1 + value2 + value3);  //ㅓ 모양
    maxnum = max(maxnum, value + value1 + value2 + value4); // ㅏ 모양
    maxnum = max(maxnum, value + value1 + value3 + value4); //ㅗ 모양
    maxnum = max(maxnum, value + value2 + value3 + value4); // ㅜ 모양

    return;

}   


void maxtet(vector<vector <int>>& arr, int num1, int num2, vector< vector <bool>>& visit, int starti, int startj, int value, int square) {
    
        
        
        if (square == 4) {
            maxnum = max(maxnum, value);
            return;
        }

        if (starti - 1 >= 0) {
            if (!visit[starti - 1][startj]) {
                visit[starti - 1][startj] = 1;
                maxtet(arr, num1, num2, visit, starti - 1, startj, value + arr[starti - 1][startj], square + 1);
                visit[starti - 1][startj] = 0;
            }
        }
        if (starti + 1 < num1) {
            if (!visit[starti + 1][startj]) {
                visit[starti + 1][startj] = 1;
                maxtet(arr, num1, num2, visit, starti + 1, startj, value + arr[starti + 1][startj], square + 1);
                visit[starti + 1][startj] = 0;
            }
        }
        if (startj - 1 >= 0 ) {
            if (!visit[starti][startj - 1]) {
                visit[starti][startj - 1] = 1;
                maxtet(arr, num1, num2, visit, starti, startj - 1, value + arr[starti][startj - 1], square + 1);
                visit[starti][startj - 1] = 0;
            }

        }
        if (startj + 1 < num2) {
            if (!visit[starti][startj + 1]) {
                visit[starti][startj + 1] = 1;
                maxtet(arr, num1, num2, visit, starti, startj + 1, value + arr[starti][startj + 1], square + 1);
                visit[starti][startj + 1] = 0;
            }
        }
    
        return;

}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int num1, num2;

    cin >> num1 >> num2;
    vector <vector <int>> arr(num1, vector<int>(num2));

    for (int i = 0; i < num1; i++)
        for (int j = 0; j < num2; j++)
            cin >> arr[i][j];

    vector <vector <bool>> visit(num1, vector <bool>(num2));

    for(int i = 0 ; i < num1; i++)
        for (int j = 0; j < num2; j++) {
            visit[i][j] = 1;
            maxtet2(arr, num1, num2, i, j);
            maxtet(arr, num1, num2, visit, i, j, arr[i][j], 1);
            visit[i][j] = 0;
        }


    cout << maxnum;

    return 0;
}
