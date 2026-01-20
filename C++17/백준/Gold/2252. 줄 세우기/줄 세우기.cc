#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M; // 학생수, 키재본횟수
    vector<vector<int>> adj(N + 1);
    vector<int> D(N + 1, 0);

    for (int i = 0; i < M; ++i) {
        int t1, t2;
        cin >> t1 >> t2;
        adj[t1].push_back(t2);
    }

    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j < adj[i].size(); ++j) {
            D[adj[i][j]]++;
        }
    }
    queue<int> q;
    for (int i = 1; i <= N; ++i) {
        if (!D[i]) {
            q.push(i);
        }
    }

    int select;
    std::vector<int> answer;
    while (!q.empty()) {
        select = q.front();
        D[select]--;
        answer.push_back(select);
        q.pop();

        for (int i = 0; i < adj[select].size(); ++i) {
            D[adj[select][i]]--;
            if (!D[adj[select][i]]) {
                q.push(adj[select][i]);
            }
        }
    }
    for (int i = 0; i < answer.size(); ++i) {
        cout << answer[i] << " ";
    }
}