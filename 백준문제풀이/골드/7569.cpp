#include <iostream>
#include <unordered_map>
#include <stack>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct road {
    int z;
    int y;
    int x;
    int dist;
};


void bfs(vector<vector<vector<int>>>& tomato, vector<vector<vector <int>>>& visit, int x, int y, int z, queue<road> &q) {

    while(!q.empty()) {
        int startx = q.front().x;
        int starty = q.front().y;
        int startz = q.front().z;
        int dist = q.front().dist;
        q.pop();

        if (startz - 1 >= 0 && tomato[startz - 1][starty][startx] == 0)
            if (!visit[startz - 1][starty][startx]) {
                visit[startz - 1][starty][startx] = dist + 1;
                q.push({ startz - 1, starty, startx, dist + 1 });
            }
            
        if (startz + 1 < z && tomato[startz + 1][starty][startx] == 0)
            if (!visit[startz + 1][starty][startx]) {
                visit[startz + 1][starty][startx] = dist + 1;
                q.push({ startz + 1, starty, startx, dist + 1 });
            }

        if (starty - 1 >= 0 && tomato[startz][starty - 1][startx] == 0)
            if (!visit[startz][starty - 1][startx]) {
                visit[startz][starty - 1][startx] = dist + 1;
                q.push({ startz, starty - 1, startx, dist+1 });
            }
        if (starty + 1 < y && tomato[startz][starty + 1][startx] == 0)
            if (!visit[startz][starty + 1][startx]) {
                visit[startz][starty + 1][startx] = dist + 1;
                q.push({ startz, starty + 1, startx, dist+1 });
            }
        if (startx - 1 >= 0 && tomato[startz][starty][startx - 1] == 0)
            if (!visit[startz][starty][startx - 1]) {
                visit[startz][starty][startx - 1] = dist + 1;
                q.push({ startz, starty, startx - 1 , dist + 1});
            }
        if (startx + 1 < x && tomato[startz][starty][startx + 1] == 0)
            if (!visit[startz][starty][startx + 1]) {
                visit[startz][starty][startx + 1] = dist + 1;
                q.push({ startz, starty, startx + 1 , dist + 1});
            }

        
    }

}





int main() {



    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int x, y, z;
    cin >> x >> y >> z;

    vector<vector<vector <int>>> tomato(z, vector<vector<int>>(y, vector<int> (x)));
    vector<vector<vector<int>>> visit(z, vector<vector<int>>(y, vector<int>(x)));
    bool perfect = 1;


    queue <road> q;

    for (int i = z - 1; i >= 0; i--)
        for (int j = 0; j < y; j++)
            for (int k = 0; k < x; k++) {
                cin >> tomato[i][j][k];
                if (tomato[i][j][k] == 0)
                    perfect = 0;
                else if (tomato[i][j][k] == 1)
                    q.push({ i, j ,k , 0 });
            }

    bfs(tomato, visit, x, y, z, q);

    int day = 0;
    if (perfect)
        cout << day;
    else {
        for (int i = 0; i < z; i++)
            for (int j = 0; j < y; j++)
                for (int k = 0; k < x; k++) {
                    if (visit[i][j][k] == 0 && tomato[i][j][k] == 0) {
                        cout << -1;
                        return 0;
                    }
                    if (visit[i][j][k] > day)
                        day = visit[i][j][k];
                }
        cout << day;
    }

    return 0;
}



