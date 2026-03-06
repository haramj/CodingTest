#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

static vector<vector<int>> adj;
static vector<int> visited;

static int N, M;
static int cnt = 0;

void dfs(int cur, int depth) {
    if (cnt == N) {
        return;
    }
    visited[cur] = ++cnt;
    sort(adj[cur].begin(), adj[cur].end());
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

    int R;
    cin >> N >> M >> R;

    adj = vector<vector<int>>(N + 1);

    for (int i = 0; i < M; ++i) {
        int s, e;
        cin >> s >> e;
        adj[s].push_back(e);
        adj[e].push_back(s);
    }

    visited = vector<int>(N + 1, 0);

    dfs(R, 1);

    for (int i = 1; i <= N; ++i) {
        cout << visited[i] << "\n";
    }
    return 0;
}