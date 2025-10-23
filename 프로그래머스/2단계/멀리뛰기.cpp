#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
    long long answer = 0;
    
    if(n == 1){
        answer = 1;
    }
    else if(n == 2) {
        answer = 2;
    } else{
        int a1 = 1;
        int a2 = 2;
        int an;
        for(int i = 3; i <= n; i++){
            an = (a1 + a2) % 1234567;
            a1 = a2;
            a2 = an;
        }
        answer = an;
    }
    
    return answer;
}