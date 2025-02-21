#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    vector <bool> gift(schedules.size());

    for (int i = 0; i < schedules.size(); i++) {
        schedules[i] = schedules[i] + 10;
        if (schedules[i] % 100 > 59)
            schedules[i] = schedules[i] + 40;
        cout << schedules[i] << '\n';
    }



    for (int i = 0; i < timelogs.size(); i++) {
        for (int j = 0; j < 7; j++) {
            cout << startday << '\n';
            if (startday == 6 || startday == 7) {
                startday++;
                if (startday == 8)
                    startday = 1;
                continue;
            }

            if (timelogs[i][j] > schedules[i]) {
                gift[i] = 1;

            }
            startday++;
        }
    }

    for (int i = 0; i < gift.size(); i++)
        if (gift[i] == 0)
            answer++;

    return answer;
}