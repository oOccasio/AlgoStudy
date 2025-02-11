#include <iostream>
#include <unordered_map>
#include <stack>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;


void bfs(unordered_map<int, vector <int>> & graph, vector <int> &visit, queue<int> &q, int size) {
    
    for (int i = 0; i < size; i++) {
        int k = q.front();
        q.pop();

        for (int i = 0; i < graph[k].size(); i++)
            if (!visit[graph[k][i]]) {
                q.push(graph[k][i]);
                visit[graph[k][i]] = 1;
            }

    }
   
}




int main() {


    unordered_map <int, vector <int> > graph;
    


    int vertex, edge;
    int num1, num2,result;
    int min = 10000; 

    cin >> vertex >> edge;
    for (int i = 0; i < edge; i++) {
        cin >> num1 >> num2;
        graph[num1].push_back(num2);
        graph[num2].push_back(num1);
    }
    vector <int> visit(vertex + 1);

    for (int i = 1; i <= vertex; i++) {
        queue<int> q;
        int kevin = 0;
        int depth = 1;
        for (int j = 0; j <= vertex; j++)
            visit[j] = 0;
        q.push(i);
        while(true){
            int size = q.size();
            bfs(graph, visit, q, size);
            kevin += depth * q.size();
            depth++;
            if (q.empty())
                break;
        }
        
        if (min > kevin) {
            min = kevin;
            result = i;
                
        }

    }

    cout << result;

    return 0;
}

