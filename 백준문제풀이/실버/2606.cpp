#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <stack>

using namespace std;




int main() {

    
    int computer, edge;
    int result = 0;

    cin >> computer >> edge;

    unordered_map <int, vector<int>> graph;
    stack<int> s;
    vector <int> visit(computer + 1);

    
    int num1, num2;
    for (int i = 0; i < edge; i++) {
        cin >> num1 >> num2; 
        graph[num1].push_back(num2);
        graph[num2].push_back(num1);

    }
    
    s.push(1);

    while (!s.empty()) {
        int k = s.top();
        s.pop();
        visit[k] = 1;

        for (size_t i = 0; i < graph[k].size(); i++){
            if (visit[graph[k][i]] == 0) {
                s.push(graph[k][i]);
            }
            else
                continue;
        }
    }



    for (int i = 2; i <= computer; i++)
        if (visit[i] == 1)
            result++;
    
    cout << result;


    return 0;
}
