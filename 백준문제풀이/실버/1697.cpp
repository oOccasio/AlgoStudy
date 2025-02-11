#include <iostream>
#include <unordered_map>
#include <stack>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct graph {
    int vertex;
    int dist;

};


int bfs(int num1, int num2) {
    bool visit[100001] = { 0 };
    queue<graph> q;

    q.push({ num1, 0 });

    int vertex;
    int dist;
    while (!q.empty()) {
        vertex = q.front().vertex;
        dist = q.front().dist;
        visit[vertex] = 1;



        if (vertex == num2) {
            return q.front().dist;
        }
        q.pop();
        if (vertex - 1 >=0 && vertex - 1 < 100001 && !visit[vertex - 1])
            q.push({ vertex - 1, dist + 1 });


        if (vertex + 1 >=0 && vertex + 1 < 100001 && !visit[vertex + 1])
            q.push({ vertex + 1, dist + 1 });

        if (vertex * 2 >=0 && vertex * 2 < 100001 && !visit[vertex * 2])
            q.push({ vertex * 2, dist + 1 });



    }

    return 0;

}






int main() {

    int num1, num2;

    cin >> num1 >> num2;

    cout << bfs(num1, num2);
    return 0;
}



