// 입력 받자마자 처리하는 그리디 말고.
// 모든 입력 받은 후에 그래프 탐색으로 처리하는 방식으로 풀기.
// 각 그룹에는 서로 인접하는 애가 있어서는 안 된다.

#include <iostream>
#include <queue>
#include <vector>
#include <utility>

bool BFS(const std::vector<std::vector<int>> &adj, int V) {
    std::queue<int> q;
    // viist 색깔. 0이면 방문X / 1이면 파랑 / 2면 빨강.
    std::vector<int> visit(V + 1, 0);

    for (int k = 1; k <= V; ++k) {
        if (visit[k] == 0) {
            q.push(k);
            int currentColor = 1;
            visit[k] = 1; // 파랑으로 시작.
            while (!q.empty()) {
                int cur = q.front();
                int nextColor = (visit[cur] == 1) ? 2 : 1;
                q.pop();
                for (int i = 0; i < adj[cur].size(); ++i) {
                    if (visit[adj[cur][i]] == 0) {
                        visit[adj[cur][i]] = nextColor;
                        q.push(adj[cur][i]);
                    } else {
                        if (visit[adj[cur][i]] != nextColor) {
                            return false;
                        }
                    }
                }
            }
        }
    }

    return true;
}

int main() {
    int K;
    std::cin >> K;
    for (int k = 0; k < K; ++k) {
        int V, E; // 정점 수, 엣지 수
        std::cin >> V >> E;
        std::vector<std::vector<int>> adj(V + 1);
        for (int i = 0; i < E; ++i) {
            int v1, v2;
            std::cin >> v1 >> v2;
            adj[v1].push_back(v2);
            adj[v2].push_back(v1);
        }


        if (BFS(adj, V)) {
            std::cout << "YES" << '\n';
        } else {
            std::cout << "NO" << '\n';
        }
    }
}