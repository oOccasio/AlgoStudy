#include <iostream>
#include <unordered_map>
#include <stack>
#include <vector>

using namespace std;

void dfs(vector<bool>& visit, unordered_map<int, vector<int>> &graph, int start, stack<int> &s) {

    
  
        start = s.top();
        s.pop();
        visit[start] = 1;
        for (int i = 0; i < graph[start].size(); i++) {
            if (!visit[graph[start][i]]) {
                s.push(graph[start][i]);
                dfs(visit, graph, graph[start][i], s);
            }
            else
                continue;
        }
    return;
}


int main() {
    int vertex , edge;
    cin >> vertex >> edge;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int result = 0;

    unordered_map<int, vector<int>> graph;
    vector <bool> visit(vertex + 1);
    stack<int> s;

    int num1, num2;
    for (int i = 0; i < edge; i++) {
        cin >> num1 >> num2;
        graph[num1].push_back(num2);
        graph[num2].push_back(num1);
        
    }
    for (int i = 1; i <= vertex; i++) {
        if (visit[i])
            continue;
        s.push(i);
        dfs(visit, graph, i,s);
        result++;
    }


    cout << result;




    return 0;
}
