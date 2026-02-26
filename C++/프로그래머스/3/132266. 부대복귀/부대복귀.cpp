// 각 부대원이 여러 지역에 뿔뿔이 흩어져 특수 임무
// 지도에서 강철부대가 위치한 지역을 포함한 각 지역은 유일한 번호로 구분
// 두 지역 간의 길을 통과하는 데 걸리는 시간은 모두 1
// 최단시간에 부대로 복귀

// 적군의 방해로 인해, 임무의 시작 때와 다르게 되돌아오는 경로가 없어져 복귀가 불가능한 부대원

// 주어진 sources의 원소 순서대로 강철부대로 복귀할 수 있는 최단시간을 담은 배열
// 그래프 -> BFS 로 최단거리. (각 경로가 1이므로.)

#include <string>
#include <vector>
#include <queue>
#include <utility>

using namespace std;
typedef pair<int, int> info; // cur, distance

static vector<bool> visit;

int bfs(const vector<vector<int>> &adj, int s, int des, vector<bool> visit) {
    queue<info> q;
    q.push(info(s, 0));
    visit[s] = true;
    while (!q.empty()) {
        info cur = q.front();
        if (cur.first == des) return cur.second;
        q.pop();
        // cur.first 현재지역 cur.second 현재까지 온 거리
        for (int i = 0; i < adj[cur.first].size(); ++i) {
            // adj[cur.first][i] -> 다음 지역 번호
            if (!visit[adj[cur.first][i]]) {
                visit[adj[cur.first][i]] = true;
                q.push(info(adj[cur.first][i], cur.second + 1));
            }
        }
    }
    return -1;
}


vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < roads.size(); ++i) {
        adj[roads[i][0]].push_back(roads[i][1]);
        adj[roads[i][1]].push_back(roads[i][0]);
    }
    vector<int> answer;
    for (int i = 0; i < sources.size(); ++i) { // 지금 i라는 지역에서 목적지까지의 최단거리.
        if (sources[i] != destination) {
            visit = vector<bool>(n + 1, false);
            int distance = bfs(adj, sources[i], destination, visit);
            answer.push_back(distance);
        } else {
            answer.push_back(0);
        }
    }
    
    return answer;
}