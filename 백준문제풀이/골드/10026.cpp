#include <iostream>
#include <unordered_map>
#include <stack>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct index{

    int x;
    int y;
    char color;
};


void bfs(vector <vector <char>>& arr, vector<vector <bool>>& visit, queue <index> &q, int num) {

    while (!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        char color = q.front().color;
        q.pop();

        if (x + 1 < num && arr[y][x + 1] == color)
            if (!visit[y][x + 1]) {
                visit[y][x + 1] = 1;
                q.push({ x + 1 , y , color });
            }
        if (x - 1 >= 0 && arr[y][x - 1] == color)
            if (!visit[y][x - 1]) {
                visit[y][x - 1] = 1;
                q.push({ x - 1 , y , color });
            }
        if ( y + 1 < num && arr[y+1][x] == color)
            if (!visit[y + 1][x]) {
                visit[y+1][x] = 1;
                q.push({ x , y + 1 , color });
            }

        if (y - 1 >= 0 && arr[y - 1][x] == color)
            if (!visit[y - 1][x]) {
                visit[y - 1][x] = 1;
                q.push({ x , y - 1 , color });
            }




    }



}




int main() {


    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int num;
    cin >> num;

    vector <vector <char>> arr(num, vector <char>(num));
    vector <vector <char>> arr2(num, vector <char>(num));
    vector <vector <bool>> visit(num, vector <bool>(num));

    for (int i = 0; i < num; i++)
        for (int j = 0; j < num; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 'G')
                arr2[i][j] = 'R';
            else
                arr2[i][j] = arr[i][j];
        }

    int result1 = 0;
    int result2 = 0;
    queue<index> q;
    for(int i = 0 ; i < num; i++)
        for (int j = 0; j < num; j++) {
            if (!visit[i][j]) {
                q.push({ j , i , arr[i][j] });
                bfs(arr, visit, q, num);
                result1++;
            }
        }
    for (int i = 0; i < num; i++)
        for (int j = 0; j < num; j++)
            visit[i][j] = 0;

    for (int i = 0; i < num; i++)
        for (int j = 0; j < num; j++) {
            if (!visit[i][j]) {
                q.push({ j , i , arr2[i][j] });
                bfs(arr2, visit, q, num);
                result2++;
            }
        }
    
    cout << result1 <<  " " <<result2;
    return 0;
}



