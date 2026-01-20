#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int main() {
    int N, t;
    cin >> N;
    vector<int> buildTime(N + 1);
    vector<vector<int>> adj(N + 1);

    for (int i = 1; i <= N; ++i) { // i는 현재 건물 번호
        cin >> buildTime[i];
        while (true) {
            cin >> t; // 이전에 지어져야하는 건물
            if (t == -1) break;
            adj[t].push_back(i);
        }
    }
    vector<int> D(N + 1);
    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j < adj[i].size(); ++j) {
            D[adj[i][j]]++;
        }
    }
    vector<int> answer(N + 1);
    queue<int> q;
    for (int i = 1; i < D.size(); ++i) {
        if (D[i] == 0) {
            q.push(i);
            answer[i] = buildTime[i];
        }
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        D[cur]--;
        for (auto next : adj[cur]) {
            answer[next] = max(answer[next], answer[cur] + buildTime[next]);
            D[next]--;
            if (D[next] == 0) {
                q.push(next);
            }
        }
    }

    for (int i = 1; i <= N; ++i) {
        cout << answer[i] << '\n';
    }
}