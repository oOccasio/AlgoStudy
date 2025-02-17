#include <iostream>
#include <unordered_map>
#include <stack>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct room {
    int starttime;
    int endtime;
};

bool compare(room x, room y) {
    if (x.endtime == y.endtime)
        return x.starttime < y.starttime;
    
    return x.endtime < y.endtime;
}




int main() {


    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int num;

    cin >> num;

    vector <room> arr(num);

    for (int i = 0; i < num; i++)
        cin >> arr[i].starttime >> arr[i].endtime;

    sort(arr.begin(), arr.end(), compare);

    int result = 1;
    int time;
    time = arr[0].endtime;
    for (int i = 1; i < num; i++) {
        if (time <= arr[i].starttime) {
            time = arr[i].endtime;
            result++;
        }
    }
    

    cout << result; 


    return 0;
}



