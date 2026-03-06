#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, R;
    cin >> N >> M >> R;

    vector<vector<int>> adj(N + 1);

    for (int i = 0; i < M; ++i) {
        int s, e;
        cin >> s >> e;
        adj[s].push_back(e);
        adj[e].push_back(s);
    }

    for (int i = 1; i <= N; ++i) {
        sort(adj[i].begin(), adj[i].end(), greater<int>());
    }

    vector<int> visited(N + 1, 0);

    int cnt = 0;
    queue<int> q;
    q.push(R);
    visited[R] = ++cnt;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int i = 0; i < adj[cur].size(); ++i) {
            if (!visited[adj[cur][i]]) {
                visited[adj[cur][i]] = ++cnt;
                q.push(adj[cur][i]);
            }
        }
    }

    for (int i = 1; i <= N; ++i) {
        cout << visited[i] << '\n';
    }
    
    return 0;
}