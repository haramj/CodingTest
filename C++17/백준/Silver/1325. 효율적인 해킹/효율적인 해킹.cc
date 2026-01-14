#include <iostream>
#include <queue>
#include <vector>

int main() {
    int N, M; // 컴퓨터수,관계수
    std::cin >> N >> M;

    std::vector<std::vector<int>> adj(N + 1);
    std::vector<int> visitCount(N + 1, 0);
    std::vector<bool> visit(N + 1, false);
    std::queue<int> q;
    int count;

    for (int i = 0; i < M; ++i) {
        int t1, t2;
        std::cin >> t1 >> t2;
        adj[t2].push_back(t1);
    }

    for (int w = 1; w <= N; ++w) {
        if (adj[w].empty()) continue;

        // w 는 현재 출발하는 노드 값
        q.push(w);
        std::fill(visit.begin(), visit.end(), false);
        visit[w] = true;
        count = 1;
        while (!q.empty()) {
            int value = q.front();
            q.pop();
            for (int i = 0; i < adj[value].size(); ++i) {
                if (!visit[adj[value][i]]) {
                    count++;
                    visit[adj[value][i]] = true;
                    q.push(adj[value][i]);
                }
            }
        }
        visitCount[w] = count;
    }

    int maxCount=0;
    for (int i=0; i < visitCount.size(); ++i) {
        if (maxCount < visitCount[i]) {
            maxCount = visitCount[i];
        }
    }
    for (int  i =0; i < visitCount.size(); ++i) {
        if (maxCount == visitCount[i]) std::cout << i << " ";
    }
}