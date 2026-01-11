// 인접 2차원 리스트 인데, pair로 <연결된 정점, 거리> 이렇게 저장한 후
// 방문되지 않은 것 위주로 쫙 봤을 때 가장 긴 거리.
// 이것도 정점 개수만큼 거리 배열을 만들어서 최신화하면서 진행.
// BFS 활용

// 트리의 지름 아이디어
// 임의의 정점에서 가장 멀리 갔을 때 정점이 v1일 때.
// v1에서 가장 멀리 간 정점v2까지의 거리가 트리의 지름이다.

#include <iostream>
#include <vector>
#include <utility>
#include <queue>

static int N;
static std::vector<bool> visit(N + 1, false);
static std::vector<int> distance(N + 1, 0);
static std::queue<int> q;
static std::vector<std::vector<std::pair<int, int>>> adj(N + 1);

int BFS(int startVertex, int &farVertex) {
    int farDistance = 0;
    farVertex = startVertex;

    visit = std::vector<bool>(N + 1, false);
    distance = std::vector<int>(N + 1, 0);
    q = std::queue<int>();

    q.push(startVertex);

    while (!q.empty()) {
        int temp = q.front();
        q.pop();
        visit[temp] = true;

        for (int i = 0; i < adj[temp].size(); ++i) {
            if (!visit[adj[temp][i].first]) {
                // distance[temp] 현재 정점까지의 누적된거리.
                // adj[temp][i].first 다음정점 / adj[temp][i].second 거리
                visit[adj[temp][i].first] = true;
                distance[adj[temp][i].first] = adj[temp][i].second + distance[temp];
                if (farDistance < distance[adj[temp][i].first]) {
                    farDistance = distance[adj[temp][i].first];
                    farVertex = adj[temp][i].first;
                }
                q.push(adj[temp][i].first);
            }
        }
    }
    return farDistance;
}

int main() {
    std::cin >> N;
    adj = std::vector<std::vector<std::pair<int, int>>>(N + 1);


    for (int i = 1; i <= N; ++i) {
        int inputVertex;
        std::cin >> inputVertex;
        while (true) {
            int temp;
            std::cin >> temp;
            if (temp == -1) break;
            int tempDistance;
            std::cin >> tempDistance;
            std::pair<int, int> pair(temp, tempDistance);
            adj[inputVertex].push_back(pair);
        }
    }

    int farVertex = 0;
    BFS(1, farVertex);
    std::cout << BFS(farVertex, farVertex);
}