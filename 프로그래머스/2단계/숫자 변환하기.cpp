#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;
struct num{
    int x;
    int depth;
};

int solution(int x, int y, int n) {
    
    int answer = -1;
    queue<num> q;
    q.push({x, 0});
    vector<bool> visited (y + 1, false);
    
    
    
    while(!q.empty()){
        int depth = q.front().depth;
        int number = q.front().x;
        visited[number] = true;
        
        q.pop();
        
        if(number == y){
            answer = depth;
            break;
        }
        if(number + n <= y && visited[number+ n] == false){
            q.push({number + n, depth + 1});
        }     
        if(number * 2 <= y && visited[number * 2] == false){
            q.push({number * 2, depth + 1});
        }
        if(number * 3 <= y && visited[number * 3] == false){
            q.push({number * 3, depth + 1});
        }
        
    }
    
    return answer;
    
}