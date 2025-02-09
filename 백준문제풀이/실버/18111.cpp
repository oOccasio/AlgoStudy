#include <iostream>
#include <unordered_map>
#include <stack>
#include <vector>

using namespace std;

struct addsub {
    int add;
    int sub;
};


int main() {
    
    int row, column, block;

    cin >> row >> column >> block;

    vector <vector<int>> arr(row, vector <int>(column));
    
    for (int i = 0; i < row; i++)
        for (int j = 0; j < column; j++)
            cin >> arr[i][j];
    vector <addsub> height(257);
    vector <int> time(257);
    
    for (int k = 0; k <= 256; k++) {

        int tmp = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                if (arr[i][j] - k < 0) {
                    height[k].add += k - arr[i][j];
                }
                else {
                    height[k].sub += arr[i][j] - k;
                    tmp += arr[i][j] - k;
                }
            }
        }
        if (height[k].add > block + tmp) {
            time[k] = -1;
            continue;
        }

        time[k] = height[k].sub * 2 + height[k].add;

        
    }
    int min = time[0];
    int result = 0;
    for (int i = 1; i <= 256; i++) {
        if (time[i] < 0)
            continue;
        if (min >= time[i]) {
            min = time[i];
            result = i;
        }
    }
    cout << min << " " << result;


    
    



    return 0;
}
