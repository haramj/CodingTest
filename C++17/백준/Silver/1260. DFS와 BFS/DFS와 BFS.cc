// 방문할 수 있는 정점이 여러 개인 경우에는 정점 번호가 작은 것을 먼저 방문
// 양방향 !
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

static std::vector<std::vector<int>> adj;
static std::vector<int> visit;
static std::queue<int> q;

void DFS(int v) {
    visit[v] = true;
    std::cout << v << ' ';
    std::sort(adj[v].begin(), adj[v].end());
    for (int i = 0; i < adj[v].size(); ++i) {
        if (visit[adj[v][i]] == false) {
            visit[adj[v][i]] = true;
            DFS(adj[v][i]);
        }
    }
}

void BFS(int v) {
    visit[v] = true;
    q.push(v);
    while (!q.empty()) {
        int temp = q.front();
        std::cout << temp << ' ';
        q.pop();
        std::sort(adj[temp].begin(), adj[temp].end());
        for (int i = 0; i < adj[temp].size(); ++i) {
            if (visit[adj[temp][i]] == false) {
                q.push(adj[temp][i]);
                visit[adj[temp][i]] = true;
            }
        }
    }
}

int main() {
    int N, M, V; // 정점개수 간선개수 탐색시작할번호
    std::cin >> N >> M >> V;
    adj = std::vector<std::vector<int>>(N + 1);
    q = std::queue<int>();
    for (int i = 0; i < M; ++i) {
        int v1, v2;
        std::cin >> v1 >> v2;
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
    }

    visit = std::vector<int>(N + 1, false);
    DFS(V);
    visit = std::vector<int>(N + 1, false);
    std::cout << '\n';
    BFS(V);
}
