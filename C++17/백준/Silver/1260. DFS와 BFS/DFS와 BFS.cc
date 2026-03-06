#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

static int N, M, V;
static vector<bool> visited;
static vector<vector<int>> adj;

void DFS(int cur) {
    cout << cur << ' ';

    visited[cur] = true;

    for (int i = 0; i < adj[cur].size(); ++i) {
        if (!visited[adj[cur][i]]) {
            DFS(adj[cur][i]);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> V;

    adj = vector<vector<int>>(N + 1);

    for (int i = 0; i < M; ++i) {
        int s, e;
        cin >> s >> e;
        adj[s].push_back(e);
        adj[e].push_back(s);
    }

    for (int i = 1; i <= N; ++i) {
        sort(adj[i].begin(), adj[i].end());
    }

    // DFS
    visited = vector<bool>(N + 1, false);
    DFS(V);

    cout << '\n';

    // BFS
    visited = vector<bool>(N + 1, false);
    queue<int> q;
    q.push(V);
    visited[V] = true;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        cout << cur << ' ';
        for (int i = 0; i < adj[cur].size(); ++i) {
            if (!visited[adj[cur][i]]) {
                visited[adj[cur][i]] = true;
                q.push(adj[cur][i]);
            }
        }
    }

    return 0;
}