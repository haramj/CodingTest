#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

typedef pair<int, int> info; // 현재층 / 현재까지 버튼 누른 횟수

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int F, S, G, U, D;
    cin >> F >> S >> G >> U >> D;

    vector<bool> visited(F + 1, false);
    queue<info> q;

    q.push(info(S, 0));
    visited[S] = true;

    while(!q.empty()) {
        int curFloor = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if (curFloor == G) {
            cout << cnt;
            return 0;
        }
        if (curFloor + U >= 1 && curFloor + U <= F && !visited[curFloor + U]) {
            q.push(info(curFloor + U, cnt + 1));
            visited[curFloor + U] = true;
        }
        if (curFloor - D >= 1 && curFloor - D <= F && !visited[curFloor - D]) {
            q.push(info(curFloor - D, cnt + 1));
            visited[curFloor - D] = true;
        }
    }

    cout << "use the stairs";
    return 0;
}