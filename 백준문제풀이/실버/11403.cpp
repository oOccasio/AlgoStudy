#include <iostream>
#include <unordered_map>
#include <stack>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

void dfs(vector <bool>& visit, unordered_map<int, vector<int>>& graph, vector <vector <int>> &result, stack <int> &s, int start) {

    int k = s.top();
    s.pop();
   

    for(int i = 0 ; i < graph[k].size(); i++)
        if (!visit[graph[k][i]]) {
            visit[graph[k][i]] = 1;
            s.push(graph[k][i]);
            result[start][graph[k][i]] = 1;
            dfs(visit, graph, result, s, start);
        }

    return;

}





int main() {



    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    int num; 
    cin >> num;

    vector <vector <int>> arr(num, vector <int>(num));
    unordered_map <int, vector <int>> graph;
    vector <bool> visit(num + 1);
    vector <vector <int>> result(num, vector<int>(num));
    stack <int> s;


    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 1) {
                graph[i].push_back(j);               
            }

        }
    }



    for (int i = 0; i < num; i++) {
        s.push(i);
        dfs(visit, graph, result, s, i);
        for (int j = 0; j < num; j++)
            visit[j] = 0;
        
    }


    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            cout << result[i][j] << " ";
        }
        cout << '\n';
    }








    
    return 0;
}



