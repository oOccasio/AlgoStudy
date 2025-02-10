#include <iostream>
#include <unordered_map>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;
int friendnum = 0;


void search(vector <vector <char>>& arr, int startr, int startc, int row, int column, vector <vector <bool>> & visit) {
    if (startr < 0 || startc < 0)
        return;
    
    if (startr >= row || startc >= column)
        return;
    
    if(visit[startr][startc] == 1)
        return;
    
    visit[startr][startc] = 1;

    if (arr[startr][startc] == 'X')
        return;

    if (arr[startr][startc] == 'P')
        friendnum++;

    search(arr, startr - 1, startc, row, column, visit);
    search(arr, startr + 1, startc, row, column, visit);
    search(arr, startr, startc + 1, row, column, visit);
    search(arr, startr, startc - 1, row, column, visit);
    return;
}


int main() {


    int row, column;

    cin >> row >> column;

    vector <vector<char>> arr(row, vector<char>(column));
    vector <vector<bool>> visit(row, vector<bool>(column));

    int startr, startc;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 'I') {
                startr = i;
                startc = j;
            }
               
        }
    }
    search(arr, startr, startc, row, column, visit);

    if (friendnum == 0)
        cout << "TT";
    else
        cout << friendnum;


    return 0;
}

