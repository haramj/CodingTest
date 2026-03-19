#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> v(N + 1, 0);
    vector<bool> visited(N + 1, false);

    for (int i = 1; i <= N; ++i) {
        int tmp;
        cin >> tmp;
        v[i] = tmp;
    }

    int start;
    cin >> start;

    queue<int> q;
    int answer = 0;

    visited[start] = true;
    answer++;
    q.push(start);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        if (cur + v[cur] <= N && !visited[cur + v[cur]]) {
            visited[cur + v[cur]] = true;
            answer++;
            q.push(cur + v[cur]);
        } if (cur - v[cur] >= 1 && !visited[cur - v[cur]]) {
            visited[cur - v[cur]] = true;
            answer++;
            q.push(cur - v[cur]);
        }
    }

    cout << answer;
    return 0;
}