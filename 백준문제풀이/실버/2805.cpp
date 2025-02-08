#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int Search(vector <int>& tree, int maximum, int target) {
    

    
    int high = maximum;
    int low = 0;
    int recent = 0;

    while (low <= high) {
        int mid = (low + high) / 2;
        long sum = 0;
        for (int i = 0; i < tree.size(); i++) {
            if (tree[i] - mid > 0)
                sum += tree[i] - mid;
        }
            
        if (sum == target) {
            recent = mid;
            low =low + 1;
        }
        else if (sum > target) {
            low = mid + 1;
            recent = mid;
        }
        else 
            high = mid - 1;
       
        
    }
   

    return recent;
}


int main() {

    int tree;
    int target;


    cin >> tree >> target;

    vector <int> arr(tree);


    for (int i = 0; i < tree; i++)
        cin >> arr[i];

    sort(arr.begin(), arr.end());

    int maximum = arr[tree - 1];

    cout << Search(arr, maximum, target);


    return 0;
}
