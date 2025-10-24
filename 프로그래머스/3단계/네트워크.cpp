#include <string>
#include <vector>

using namespace std;
void dfs (int n, vector<vector<int>> &computers, vector<int> &visit, int k ){
    if(visit[k] == 0){
        visit[k] = 1;
        for(int i = 0 ; i < n; i++){
            if(computers[k][i] == 1 && k != i){
                dfs(n, computers, visit, i);
            }
        }  
    }
}

int solution(int n, vector<vector<int>> computers) {
    
    vector<int> visit(n);
    
    int answer = 0;
    
    for (int i = 0 ; i < n; i++){
        if(visit[i] == 0){
            dfs(n, computers, visit, i);   
            answer += 1;
        }
    } 
    return answer;
}

