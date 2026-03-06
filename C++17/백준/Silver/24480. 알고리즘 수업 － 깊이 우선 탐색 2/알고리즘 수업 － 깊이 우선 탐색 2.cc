#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

static int N, cnt = 0;
static vector<vector<int>> adj;
static vector<int> visited;

void dfs(int cur, int depth) {
    visited[cur] = ++cnt;
    if (cnt == N) return;

    for (int i = 0; i < adj[cur].size(); ++i) {
        if (!visited[adj[cur][i]]) {
            dfs(adj[cur][i], depth + 1);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int M, R;

    cin >> N >> M >> R;
    adj = vector<vector<int>>(N + 1);
    for (int i = 0; i < M; ++i) {
        int s, e;
        cin >> s >> e;
        adj[s].push_back(e);
        adj[e].push_back(s);
    }

    for (int i = 0; i < adj.size(); ++i) {
        sort(adj[i].begin(), adj[i].end(), greater<int>());
    }

    visited = vector<int>(N + 1, 0);

    dfs(R, 1);

    for (int i = 1; i <= N; ++i) {
        cout << visited[i] << "\n";
    }
    return 0;
}