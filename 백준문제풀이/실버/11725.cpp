#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <unordered_map>
using namespace std;

int arr[100000] = { 0 };

void tree(unordered_map<int, vector<int>> &graph, vector<bool> &visit, queue<int> & q) {
    
    while (!q.empty()) {
        int num = q.front();
        q.pop();

        for (int i = 0; i < graph[num].size(); i++) {
            if (!visit[graph[num][i]]) {
                visit[graph[num][i]] = 1;
                q.push(graph[num][i]);
                arr[graph[num][i]] = num;
            }


        }


    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int num;
    unordered_map<int, vector<int>> graph;

    cin >> num;
    int num1, num2;
    vector<bool> visit(num + 1);
    queue<int> q;


    for (int i = 0; i < num - 1; i++) {
        cin >> num1 >> num2;
        graph[num1].push_back(num2);
        graph[num2].push_back(num1);
    }

    q.push(1);
    visit[1] = 1;
    tree(graph, visit, q);


    for (int i = 2; i <= num; i++) {
        cout << arr[i] << '\n';
    }
    
    return 0;
}
