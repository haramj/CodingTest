// 1초 후에 X-1 또는 X+1로 이동하게 된다. 순간이동을 하는 경우에는 1초 후에 2*X의 위치로 이동
#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

typedef pair<int, int> info; // 위치, 현재까지 이동 횟수

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int s, e;
    cin >> s >> e;

    vector<bool> visited(100001, false);
    queue<info> q;

    q.push(info(s, 0));
    visited[s] = true;

    while (!q.empty()) {
        info cur = q.front();
        q.pop();
        if (cur.first == e) {
            cout << cur.second;
            return 0;
        }

        if (cur.first - 1 >= 0 && cur.first - 1 <= 100001 && !visited[cur.first - 1]) {
            visited[cur.first - 1] = true;
            q.push(info(cur.first - 1, cur.second + 1));
        }
        if (cur.first + 1 >= 0 && cur.first + 1 <= 100001 && !visited[cur.first + 1]) {
            visited[cur.first + 1] = true;
            q.push(info(cur.first + 1, cur.second + 1));
        }
        if (cur.first * 2 >= 0 && cur.first * 2 <= 100001 && !visited[cur.first * 2]) {
            visited[cur.first * 2] = true;
            q.push(info(cur.first * 2, cur.second + 1));
        }
    }

    return 0;
}