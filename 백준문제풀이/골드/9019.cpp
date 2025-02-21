#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int A, B;
        cin >> A >> B;

        vector<bool> visited(10000, false);
        vector<int> parent(10000, -1);
        vector<char> op(10000, ' ');

        queue<int> q;
        visited[A] = true;
        q.push(A);

        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            if (cur == B) break;

            int next = (cur * 2) % 10000;
            if (!visited[next]) {
                visited[next] = true;
                parent[next] = cur;
                op[next] = 'D';
                q.push(next);
            }

            next = (cur == 0 ? 9999 : cur - 1);
            if (!visited[next]) {
                visited[next] = true;
                parent[next] = cur;
                op[next] = 'S';
                q.push(next);
            }

            next = (cur % 1000) * 10 + (cur / 1000);
            if (!visited[next]) {
                visited[next] = true;
                parent[next] = cur;
                op[next] = 'L';
                q.push(next);
            }

            next = (cur % 10) * 1000 + (cur / 10);
            if (!visited[next]) {
                visited[next] = true;
                parent[next] = cur;
                op[next] = 'R';
                q.push(next);
            }
        }

        string ans = "";
        for (int cur = B; cur != A; cur = parent[cur])
            ans.push_back(op[cur]);
        reverse(ans.begin(), ans.end());

        cout << ans << "\n";
    }

    return 0;
}
