#include <string>
#include <vector>
#include <functional>

using namespace std;

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    function<void(int, int)> dfs = [&](int index, int sum) {
        if (index == numbers.size()) {
            if (sum == target)
                answer++;
            return;
        }

        dfs(index + 1, sum + numbers[index]);
        dfs(index + 1, sum - numbers[index]);
    };

    dfs(0, 0);
    
    return answer;
}