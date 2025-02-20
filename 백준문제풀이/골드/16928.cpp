#include <iostream>
#include <unordered_map>
#include <stack>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;


struct location {
    int loc;
    int dist;
};

int bfs(unordered_map < int, int> ladgraph, unordered_map <int, int> snagraph, queue<location>& q) {

    int max;
    while (!q.empty()) {
        int loc = q.front().loc;
        int dist = q.front().dist;
        if (loc == 100)
            return dist;
        q.pop();

        for (int i = loc + 1; i <= loc + 6 && i<= 100; i++) {
            if (ladgraph[i] != 0) {
                q.push({ ladgraph[i], dist + 1 });
                continue;
            }
            if (snagraph[i] != 0) {
                q.push({snagraph[i], dist + 1});
                continue;
            }
            max = i;
        }
        q.push({ max, dist + 1 });


        

    }



}






int main() {


    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    unordered_map <int, int> ladgraph;
    unordered_map <int, int> snagraph;
    int ladder;
    int snake;
    cin >> ladder >> snake;

    int num1, num2;
    for (int i = 0; i < ladder; i++) {
        cin >> num1 >> num2;
        ladgraph[num1] = num2;
    }
    for (int i = 0; i < snake; i++) {
        cin >> num1 >> num2;
        snagraph[num1] = num2;
    }
    

    queue <location> q;
    q.push({ 1 , 0 });
    
    cout << bfs(ladgraph, snagraph, q);


    return 0;


}



