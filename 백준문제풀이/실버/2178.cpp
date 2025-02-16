#include <iostream>
#include <unordered_map>
#include <stack>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

bool endpoint = false;
int result = 0;


struct dist {
    int x;
    int y;
    int dis;
};

void Search(vector <vector<int>>& maze, int starta, int startb, vector<vector <bool>>& visit, queue<dist> &q, int num1, int num2) {

    int dis = q.front().dis;

    
    visit[starta][startb] = 1;
    

    while (!q.empty()) {
    
        starta = q.front().x;
        startb = q.front().y;
        dis = q.front().dis;
        q.pop();

        if (starta == num1 - 1 && startb == num2 - 1) {
            cout << dis;
            break;

        }
            
        if (starta + 1 < num1 && maze[starta + 1][startb] == 1) {
            if (!visit[starta + 1][startb] && endpoint == 0) {
                visit[starta + 1][startb] = 1;
                q.push({ starta + 1, startb, dis + 1 });
            }
        }
        if (startb + 1 < num2 && maze[starta][startb + 1] == 1) {
            if (!visit[starta][startb + 1] && endpoint == 0) {
                visit[starta][startb + 1] = 1;
                q.push({ starta, startb + 1, dis + 1 });
            }
        }
        if (starta - 1 >= 0 && maze[starta - 1][startb] == 1) {
            if (!visit[starta - 1][startb] && endpoint == 0) {
                visit[starta - 1][startb] = 1;
                q.push({ starta - 1, startb, dis + 1 });
            }
        }
        if (startb - 1 >= 0 && maze[starta][startb - 1] == 1) {
            if (!visit[starta][startb - 1] && endpoint == 0) {
                visit[starta][startb - 1] = 1;
                q.push({ starta, startb - 1, dis + 1 });
            }
        }
    }
}




int main() {


    int num1, num2;

    cin >> num1 >> num2;

    vector <string> str(num1);
    vector <vector <int>> arr(num1, vector <int>(num2));
    for (int i = 0; i < num1; i++)
        cin >> str[i];

    vector <vector <bool>> visit(num1, vector <bool>(num2));

    for (int i = 0; i < num1; i++) {
        for (int j = 0; j < num2; j++) {
            arr[i][j] = str[i][j] - '0';
        }
    }
 
    queue<dist> q;
    q.push({ 0, 0, 1 });
    Search(arr, 0, 0, visit, q, num1, num2);

    
    return 0;
}



