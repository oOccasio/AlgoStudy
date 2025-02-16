#include <iostream>
#include <unordered_map>
#include <stack>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct location{
    int x;
    int y;
};


int result = 0;

void Search(vector <vector<int>>& apt, vector<vector <bool>>& visit, stack<location> &s, int num1) {

    result++;
    int starta = s.top().x;
    int startb = s.top().y;

    visit[starta][startb] = 1;
    

    s.pop();
       
            
        if (starta + 1 < num1 && apt[starta + 1][startb] == 1) {
            if (!visit[starta + 1][startb]) {
                s.push({ starta + 1, startb });
                Search(apt, visit, s, num1);
            }
        }
        if (startb + 1 < num1 && apt[starta][startb + 1] == 1) {
            if (!visit[starta][startb + 1]) {
                s.push({ starta, startb + 1});
                Search(apt, visit, s, num1);
            }
        }
        if (starta - 1 >= 0 && apt[starta - 1][startb] == 1) {
            if (!visit[starta - 1][startb]) {
                s.push({ starta - 1, startb});
                Search(apt, visit, s, num1);
            }
        }
        if (startb - 1 >= 0 && apt[starta][startb - 1] == 1) {
            if (!visit[starta][startb - 1]) {
                s.push({ starta, startb - 1 });
                Search(apt, visit, s, num1);
            }
        }
    
}




int main() {

    int apt = 0;

    int num1;

    cin >> num1;
    vector <int> resultarr;

    vector <string> str(num1);
    vector <vector <int>> arr(num1, vector <int>(num1));
    for (int i = 0; i < num1; i++)
        cin >> str[i];

    vector <vector <bool>> visit(num1, vector <bool>(num1));

    for (int i = 0; i < num1; i++) {
        for (int j = 0; j < num1; j++) {
            arr[i][j] = str[i][j] - '0';
        }
    }
    int index = 0;
    stack <location> s;
    for (int i = 0; i < num1; i++) {
        for (int j = 0; j < num1; j++) {
            if (arr[i][j] == 1) {
                if (!visit[i][j]) {
                    s.push({ i, j });
                    Search(arr, visit, s, num1);
                    resultarr.push_back(result);
                    apt++;
                }
            }
            result = 0;

        }
    }

    sort(resultarr.begin(), resultarr.end());

    cout << apt << '\n';
    for (int i = 0; i < resultarr.size(); i++)
        cout << resultarr[i] << '\n';
    
    return 0;
}



