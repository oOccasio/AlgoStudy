#include <iostream>
#include <vector>
using namespace std;

int whitenum = 0;
int bluenum = 0;

bool bluecheck(int start1, int end1, int start2, int end2, vector <vector <int>>& arr) {
    for (int i = start1; i <= end1; i++) {
        for (int j = start2; j <= end2; j++) {
            if (arr[i][j] == 0) return false;
        }
    }
    return true;
}

bool whitecheck(int start1, int end1, int start2, int end2, vector <vector <int>>& arr) {
    for (int i = start1; i <= end1; i++) {
        for (int j = start2; j <= end2; j++) {
            if (arr[i][j] == 1) return false;
        }
    }
    return true;
}

void cut(vector <vector <int>>& arr, int start1, int end1, int start2, int end2) {
    if (bluecheck(start1, end1, start2, end2, arr)) {
        bluenum++;
        return;
    }
    if (whitecheck(start1, end1, start2, end2, arr)) {
        whitenum++;
        return;
    }

    int mid1 = (start1 + end1) / 2;
    int mid2 = (start2 + end2) / 2;

    cut(arr, start1, mid1, start2, mid2);  
    cut(arr, start1, mid1, mid2 + 1, end2);
    cut(arr, mid1 + 1, end1, start2, mid2);
    cut(arr, mid1 + 1, end1, mid2 + 1, end2);
}

int main() {
    int square;
    cin >> square;

    vector <vector <int>> arr(square, vector <int>(square));

    for (int i = 0; i < square; i++)
        for (int j = 0; j < square; j++)
            cin >> arr[i][j];

    if (bluecheck(0, square - 1, 0, square - 1, arr))
        bluenum++;
    else if (whitecheck(0, square - 1, 0, square - 1, arr))
        whitenum++;
    else
        cut(arr, 0, square - 1, 0, square - 1);

    cout << whitenum << '\n' << bluenum;
    return 0;
}
