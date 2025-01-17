#include <iostream>
using namespace std;

int rest_is_3muliply(int sugar, int result){

    int sugar_rest = sugar % result;
    int rest_result = 0;

    while(sugar_rest != sugar){
        if(sugar_rest % 3 == 0)
        {
            rest_result = sugar_rest / 3;
            cout << result + rest_result;
        }
        else{
            sugar_rest = sugar_rest + 5;
        }
    }
    if (sugar_rest == sugar)
        cout << -1;

}






int main() {
	int sugar;
    int result;
	
	cin >> sugar;

	
	if (sugar % 5 == 0)
	{
		result = sugar / 5;
		cout << result;
	}
	else
	{
		result = sugar / 5;
        rest_is_3muliply(sugar, result);
	}
}