#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

struct loc {
    int x;
    int y;
    int value;
};


int bfs(vector<vector <int>>& arr, vector<vector<bool>>& visit, queue<loc>& q, int num1, int num2) {

    int result = 0;

    while (!q.empty()) {
        result += q.front().value;
        int x = q.front().x;
        int y = q.front().y;
        q.pop();

        if (x - 1 >= 0 && arr[y][x - 1] != 0)
            if (!visit[y][x - 1]) {
                visit[y][x - 1] = 1;
                q.push({ x - 1, y, arr[y][x - 1] });
            }
        if (x + 1 < num2 && arr[y][x + 1] != 0)
            if (!visit[y][x + 1]) {
                visit[y][x + 1] = 1;
                q.push({ x + 1, y, arr[y][x + 1] });
            }

        if (y - 1 >= 0 && arr[y - 1][x] != 0)
            if (!visit[y - 1][x]) {
                visit[y - 1][x] = 1;
                q.push({ x, y - 1, arr[y - 1][x] });
            }

        if (y + 1 < num1 && arr[y + 1][x] != 0)
            if (!visit[y + 1][x]) {
                visit[y + 1][x] = 1;
                q.push({ x, y + 1, arr[y + 1][x] });
            }

    }
    return result;


}


vector<int> solution(vector<string> maps) {
    vector<int> answer;
    int num1 = maps.size();
    int num2 = maps[0].size();

    vector<vector <int>> arr(num1, vector <int>(num2));
    vector<vector <bool>> visit(num1, vector <bool>(num2));




    for (int i = 0; i < num1; i++) {
        for (int j = 0; j < num2; j++) {
            if (maps[i][j] == 'X')
                arr[i][j] = 0;
            else
                arr[i][j] = maps[i][j] - '0';
        }
    }

    queue<loc> q;


    for (int i = 0; i < num1; i++) {
        for (int j = 0; j < num2; j++)
            if (arr[i][j] != 0) {
                if (!visit[i][j]) {
                    q.push({ j , i, arr[i][j] });
                    visit[i][j] = 1;
                    int result = bfs(arr, visit, q, num1, num2);
                    if (result)
                        answer.push_back(result);
                }
            }
    }

    if (answer.size() == 0)
        answer.push_back(-1);
    else
        sort(answer.begin(), answer.end());


    return answer;



}


