// AM 02:06
#include <iostream>
#include <vector>

using namespace std;

static vector<bool> visited;
static vector<int> answer;

void DFS(int n, vector<vector<int>> &adj, int parent) {
    visited[n] = true;
    answer[n] = parent;
    if (n != 1 && adj[n].size() == 1) {
        return;
    }

    for (int i = 0; i < adj[n].size(); ++i) {
        if (!visited[adj[n][i]]) {
            DFS(adj[n][i], adj, n);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<vector<int>> adj(N + 1);
    visited = vector<bool>(N + 1, false);
    answer = vector<int>(N + 1, 0);

    for (int i = 1; i <= N - 1; ++i) {
        int s, e;
        cin >> s >> e;
        adj[s].push_back(e);
        adj[e].push_back(s);
    }

    // adj[i].size() 가 1이면 얘는 자식이 없음. (i >= 2)
    // adj[i].size() 가 2이면 자식 하나.
    // adj[2].size() 가 3이면 자식 둘.
    // DFS로 1을 찾을 때 까지 탐색을 하는데, 그 때 부모 찍고 재귀 돌아오는 분기 때 바로 출력.
    DFS(1, adj, 0);
    for (int i = 2; i <= N; ++i) {
        cout << answer[i] << '\n';
    }
}