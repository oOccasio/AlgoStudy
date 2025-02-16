#include <iostream>
#include <queue>
using namespace std;

int main() {
    int num;
    queue<int> q;
    cin >> num;
    int result = 0;  // �ʱ�ȭ �ʿ�
    int num1;
    int fruit[10] = { 0 };  // ���� ���� ���� �迭

    for (int i = 0; i < num; i++) {
        int fruitnum = 0;  // ���� ���� ����
        cin >> num1;

        q.push(num1);
        fruit[num1]++;

        // ���� ���� ���� ���� ���
        for (int i = 1; i < 10; i++)
            if (fruit[i] != 0)
                fruitnum++;

        while (fruitnum > 2) {
            int activefruit = q.front();
            q.pop();
            fruit[activefruit]--;

            fruitnum = 0;  
            for (int i = 1; i < 10; i++)
                if (fruit[i] != 0)
                    fruitnum++;
        }

        result = max(result, static_cast<int>(q.size()));  
    }

    cout << result;
    return 0;
}
