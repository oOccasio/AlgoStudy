#include <iostream>
#include <unordered_map>
#include <stack>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct road {
    int x;
    int y;
    int dist;
};


void bfs(vector <vector<int>>& arr, vector <vector <int>>& result, int num1, int num2, queue<road> &q, vector <vector <bool>> &visit  ) {


    while (!q.empty()) {
        int dis = q.front().dist;
        int x = q.front().x;
        int y = q.front().y;
        q.pop();
        result[x][y] = dis;

        if (x - 1 >= 0 && arr[x - 1][y] == 1)
            if (!visit[x - 1][y]) {
                q.push({ x - 1, y , dis + 1 });
                visit[x - 1][y] = 1;
            }
        if (y - 1 >= 0 && arr[x][y - 1] == 1)
            if (!visit[x][y - 1]) {
                q.push({ x, y - 1, dis + 1 });
                visit[x][y - 1] = 1;
            }
        if (x + 1 < num1 && arr[x + 1][y] == 1)
            if (!visit[x + 1][y]) {
                q.push({ x + 1, y, dis + 1 });
                visit[x + 1][y] = 1;
            }
        if (y + 1 < num2 && arr[x][y + 1] == 1)
            if (!visit[x][y + 1]) {
                q.push({ x, y + 1, dis + 1 });
                visit[x][y + 1] = 1;
            }


    }



}






int main() {



    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    int num1, num2;

    cin >> num1 >> num2;

    vector <vector <int>> arr(num1, vector<int>(num2));
    vector <vector <int>> result(num1, vector <int>(num2));
    vector <vector <bool>> visit(num1, vector <bool>(num2));

    queue <road> q;

    for (int i = 0; i < num1; i++) {
        for (int j = 0; j < num2; j++)
            cin >> arr[i][j];
    }

    for (int i = 0; i < num1; i++)
        for (int j = 0; j < num2; j++)
            if (arr[i][j] == 2) {
                q.push({ i, j, 0 });
                bfs(arr, result, num1, num2, q, visit);
            }



    for (int i = 0; i < num1; i++) {
        for (int j = 0; j < num2; j++) {
            if (result[i][j] == 0)
                if (arr[i][j] == 1) {
                    cout << -1 << " ";
                    continue;
                }
            
            cout << result[i][j] << " ";
        }

        cout << '\n';

    }



    
    return 0;
}



