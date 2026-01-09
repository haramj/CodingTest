// 양방향 그래프
// A와 B는 친구다
// B와 C는 친구다
// C와 D는 친구다
// D와 E는 친구다.
// -> 위 조건을 만족하는 ABCDE있으면 1.

#include <iostream>
#include <vector>

static std::vector<bool> visit;
static std::vector<std::vector<int>> adj;
static bool arrive;

void DFS(int n, int depth) {
    if (arrive) return;

    if (depth == 4) {
        arrive = true;
        return;
    }
    visit[n] = true;
    for (int i = 0; i < adj[n].size(); ++i) {
        if (!visit[adj[n][i]]) {
            DFS(adj[n][i], depth + 1);
        }
    }
    visit[n] = false;
}

int main() {
    int N, M; // 사람수 / 친구관계수
    // 깊이가 4가 되면 1 / 아니면 0
    std::cin >> N >> M;
    arrive = false;
    adj = std::vector<std::vector<int>>(N);

    for (int i = 0; i < M; ++i) {
        int tmp1, tmp2;
        std::cin >> tmp1 >> tmp2;
        adj[tmp1].push_back(tmp2);
        adj[tmp2].push_back(tmp1);
    }
    for (int i = 0; i < N; ++i) {
        visit = std::vector<bool>(N, false);
        DFS(i, 0);
    }
    if (arrive) {
        std::cout << 1;
    } else {
        std::cout << 0;
    }
    return 0;
}