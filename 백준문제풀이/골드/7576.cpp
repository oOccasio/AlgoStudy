#include <iostream>
#include <unordered_map>
#include <stack>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct road {
    int y;
    int x;
    int dist;
};


void bfs(vector<vector<int>>& tomato, vector<vector <int>>& visit, int x, int y, queue<road> &q) {

    while(!q.empty()) {
        int startx = q.front().x;
        int starty = q.front().y;
        int dist = q.front().dist;
        q.pop();

        if (starty - 1 >= 0 && tomato[starty - 1][startx] == 0)
            if (!visit[starty - 1][startx]) {
                visit[starty - 1][startx] = dist + 1;
                q.push({ starty - 1, startx, dist+1 });
            }
        if (starty + 1 < y && tomato[starty + 1][startx] == 0)
            if (!visit[starty + 1][startx]) {
                visit[starty + 1][startx] = dist + 1;
                q.push({ starty + 1, startx, dist+1 });
            }
        if (startx - 1 >= 0 && tomato[starty][startx - 1] == 0)
            if (!visit[starty][startx - 1]) {
                visit[starty][startx - 1] = dist + 1;
                q.push({ starty, startx - 1 , dist + 1});
            }
        if (startx + 1 < x && tomato[starty][startx + 1] == 0)
            if (!visit[starty][startx + 1]) {
                visit[starty][startx + 1] = dist + 1;
                q.push({ starty, startx + 1 , dist + 1});
            }

        
    }

}





int main() {



    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int x, y;
    cin >> x >> y;

    vector<vector <int>> tomato(y, vector<int>(x));
    vector<vector<int>> visit(y, vector<int>(x));
    bool perfect = 1;


    queue <road> q;

    for (int i = 0; i < y; i++)
        for (int j = 0; j < x; j++) {
            cin >> tomato[i][j];
            if (tomato[i][j] == 0)
                perfect = 0;
            else if (tomato[i][j] == 1)
                q.push({ i, j , 0 });
        }

    bfs(tomato, visit, x, y, q);

    int day = 0;
    if (perfect)
        cout << day;
    else {
        for (int i = 0; i < y; i++)
                for (int j = 0; j < x; j++) {
                    if (visit[i][j] == 0 && tomato[i][j] == 0) {
                        cout << -1;
                        return 0;
                    }
                    if (visit[i][j] > day)
                        day = visit[i][j];
                }
        cout << day;
    }

    return 0;
}



