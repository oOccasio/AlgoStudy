#include <iostream>
#include <unordered_map>
#include <stack>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;



int z(int square, int index1, int index2, int num1, int num2, int visit) {

    int mid = square / 2;
    int plus = square * square / 4;

    if (num1 == index1 && num2 == index2) {
        return visit;
    }
    

    if (num1 < index1 + mid) {
        if (num2 < index2 + mid) {
            return z(mid, index1, index2, num1, num2, visit);
        }
        else
            return z(mid, index1, index2 + mid, num1, num2, visit + plus);

    }
    else {
        if (num2 < index2 + mid) {
            return z(mid, index1 + mid, index2, num1, num2, visit + plus * 2);
        }
        else
            return z(mid, index1 + mid, index2 + mid, num1, num2, visit + plus * 3);

    }


}



int main() {


    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int number, num1, num2;
    cin >> number >> num1 >> num2;

    int square = 1;
    for (int i = 0; i < number; i++)
        square *= 2;

    
    cout << z(square, 0, 0, num1, num2,0);

    
    return 0;
}



