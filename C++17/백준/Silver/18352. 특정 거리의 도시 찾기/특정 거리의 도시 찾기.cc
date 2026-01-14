// 1-N번까지 도시와 단방향 도로 존재 / 도로 거리 1
// X로부터 갈 수 있는 모든 도시 중 최단 거리가 정확히 K인
// 모든 도시들의 번호 출력.
// 도시개수N 도로개수M K X
// 단방향도로.
#include <iostream>
#include <vector>
#include <queue>

int main() {
    int N, M, K, X, temp;
    std::cin >> N >> M >> K >> X;
    std::vector<std::vector<int>> adj(N + 1);
    std::vector<bool> visit(N + 1, false);
    std::vector<int> distance(N + 1, 0);
    std::queue<int> q;
    for (int i = 0; i < M; ++i) {
        int t1, t2;
        std::cin >> t1 >> t2;
        adj[t1].push_back(t2);
    }

    q.push(X);
    while (!q.empty()) {
        temp = q.front();
        q.pop();
        visit[temp] = true;
        for (int i = 0; i < adj[temp].size(); ++i) {
            if (!visit[adj[temp][i]]) {
                visit[adj[temp][i]] = true;
                distance[adj[temp][i]] = distance[temp] + 1;
                q.push(adj[temp][i]);
            }
        }
    }
    bool good = false;
    for (int i = 1; i <= N; ++i) {
        if (distance[i] == K) {
            std::cout << i << '\n';
            good = true;
        }
    }

    if (!good) {
        std::cout << -1;
    }
}