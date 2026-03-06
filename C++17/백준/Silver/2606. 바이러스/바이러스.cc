#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> adj(N + 1);

    for (int i = 0; i < M; ++i) {
        int s, e;
        cin >> s >> e;
        adj[s].push_back(e);
        adj[e].push_back(s);
    }

    vector<bool> visited(N + 1, false);

    int answer = 0;
    queue<int> q;

    visited[1] = true;
    q.push(1);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < adj[cur].size(); ++i) {
            if (!visited[adj[cur][i]]) {
                visited[adj[cur][i]] = true;
                q.push(adj[cur][i]);
                answer++;
            }
        }
    }

    cout << answer;

    return 0;
}