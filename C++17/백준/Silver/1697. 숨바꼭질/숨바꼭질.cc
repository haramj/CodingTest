#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

typedef pair<int, int> info;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K; // 0 ~ 100,000
    cin >> N >> K;

    queue<info> q;
    vector<bool> visited(100001, false);

    q.push(info(N, 0));
    visited[N] = true;

    while (!q.empty()) {
        info cur = q.front();// 위치, 현재까지의 시간.
        q.pop();

        if (cur.first == K) {
            cout << cur.second;
            return 0;
        }

        if (cur.first - 1 >= 0 && !visited[cur.first - 1]) {
            q.push(info(cur.first - 1, cur.second + 1));
            visited[cur.first - 1] = true;
        }

        if (cur.first + 1 < 100001 && !visited[cur.first + 1]) {
            q.push(info(cur.first + 1, cur.second + 1));
            visited[cur.first + 1] = true;
        }

        if (cur.first * 2 < 100001 && !visited[cur.first * 2]) {
            q.push(info(cur.first * 2, cur.second + 1));
            visited[cur.first * 2] = true;
        }
    }
    return 0;
}