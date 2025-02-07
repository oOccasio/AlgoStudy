#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <stack>
#include <queue>
using namespace std;

void DFS(int i, unordered_map <int, vector<int>>& graph, vector <int>& visit, stack<int> &s) {
    int k;
    k = s.top();
    s.pop();
    visit[k] = 1;
    cout << k << " ";

    for (int i = 0; i < int(graph[k].size()); i++)
        if (!visit[graph[k][i]]) {
            s.push(graph[k][i]);
            DFS(graph[k][i], graph, visit, s);
        }
        else
            continue;

}

void BFS(int i, unordered_map <int, vector<int>>& graph, vector <int>& visit, queue<int>& q) {
    while (!q.empty()) {
        int k;
        k = q.front();
        q.pop();
        visit[k] = 0;
        cout << k << " ";

        for (int i = 0; i < int(graph[k].size()); i++) {
            if (visit[graph[k][i]]) {
                q.push(graph[k][i]);
                visit[graph[k][i]] = 0;

            }
            else
                continue;
        }

    }
}





int main(){

    int vertex, edge, start;

    cin >> vertex >> edge >> start;

    unordered_map <int , vector<int>> graph;
    vector <int> visit(vertex + 1);

    int num1, num2;
    for (int i = 0; i < edge; i++) {
        cin >> num1 >> num2;
        graph[num1].push_back(num2);
        graph[num2].push_back(num1);

    }
    for (int i = 1; i <= vertex; i++)
        sort(graph[i].begin(), graph[i].end());

    stack<int> s;
    queue<int> q;
    
    s.push(start);
    DFS(start, graph, visit, s);
    cout << '\n';
    q.push(start);
    BFS(start, graph, visit, q);
    



    
    return 0;
}
