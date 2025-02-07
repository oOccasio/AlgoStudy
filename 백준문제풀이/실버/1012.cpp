#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <stack>
#include <queue>
using namespace std;

void DFS(int i, unordered_map <int, vector<int>>& graph, vector <bool>& visit, stack<int>& s) {
    int k;
    k = s.top();
    s.pop();
    visit[k] = 1;

    for (int i = 0; i < int(graph[k].size()); i++)
        if (!visit[graph[k][i]]) {
            s.push(graph[k][i]);
            DFS(graph[k][i], graph, visit, s);
        }
        else
            continue;

}




int main() {

    int tc, column, row, cab;

    cin >> tc;

    while (tc--) {
        cin >> column >> row >> cab;

        vector <vector <int>> arr(row, vector <int>(column));
        unordered_map <int, vector <int>> graph;


        int num1, num2;
        for (int i = 0; i < cab; i++) {
            cin >> num1 >> num2;
            arr[num2][num1] = 1;
        }



        int index;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                if (arr[i][j] == 1) {
                    index = i * column + j;

                    if (j != column - 1 && arr[i][j + 1] == 1) {
                        graph[index].push_back(i * column + j + 1);
                        graph[i * column + j + 1].push_back(index);

                    }
                    if (i != row - 1 && arr[i + 1][j] == 1) {
                        graph[index].push_back((i + 1) * column + j);
                        graph[(i + 1) * column + j].push_back(index);
                    }
                }
            }
        }

        vector<bool> visit(row * column);
        int result = 0;
        stack<int> s;

        for (int i = 0; i < row * column; i++)
            for (int j = 0; j < graph[i].size(); j++) {
                if (visit[graph[i][j]])
                    continue;
                else {
                    s.push(graph[i][j]);
                    DFS(graph[i][j], graph, visit, s);
                    result++;
                }
            }

        int alone = 0;
        for (int i = 0; i < visit.size(); i++)
            if (visit[i])
                alone++;

        result = result + cab - alone;
        cout << result << '\n';

    }






    return 0;
}
