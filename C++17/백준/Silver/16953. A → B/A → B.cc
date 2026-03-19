// 2를 곱한다
// 1을 수의 가장 오른쪽에 추가
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <utility>

using namespace std;

typedef pair<long long, int> info;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long A, B;
    cin >> A >> B;

    queue<info> q;

    q.push(info(A, 1));

    while (!q.empty()) {
        info cur = q.front();
        q.pop();
        if (cur.first == B) {
            cout << cur.second;
            return 0;
        }
        if (cur.first * 2 <= B) {
            q.push(info(cur.first * 2, cur.second + 1));
        }

        if (cur.first * 10 + 1 <= B) {
            q.push(info(cur.first * 10 + 1, cur.second + 1));
        }
    }
    cout << -1;
    return 0;
}