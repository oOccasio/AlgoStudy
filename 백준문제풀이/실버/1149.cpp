#include <iostream>
#include <unordered_map>
#include <stack>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;


int main() {


    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    int num;
    cin >> num;

    vector <vector <int>> house(num + 1, vector<int>(3));

    int cost1, cost2, cost3;
    for (int i = 1; i <= num; i++) {

        cin >> cost1 >> cost2 >> cost3;

        house[i][0] = min(house[i - 1][1], house[i - 1][2]) + cost1;
        house[i][1] = min(house[i - 1][0], house[i - 1][2]) + cost2;
        house[i][2] = min(house[i - 1][0], house[i - 1][1]) + cost3;


    }

    cout << min(house[num][0], min(house[num][1], house[num][2]));


    return 0;


}



