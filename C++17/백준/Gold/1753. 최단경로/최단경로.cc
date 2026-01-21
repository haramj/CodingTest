#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#include <climits>

using namespace std;
typedef pair<int, int> edge; // first거리 second노드번호

int main() {
    int V, E;
    cin >> V >> E;
    int startVertex;
    cin >> startVertex;
    vector<bool> visit(V + 1, false);
    vector<vector<edge>> adj(V + 1);
    vector<int> ans(V + 1);
    priority_queue<edge, vector<edge>, greater<edge>> q;

    for (int i = 1; i <= E; ++i) {
        int s, e, weight;
        cin >> s >> e >> weight;
        edge temp = edge(weight, e);
        adj[s].push_back(temp);
    }

    for (int i = 1; i <= V; ++i) {
        if (i == startVertex) {
            ans[i] = 0;
            q.push(edge(0, i));
        } else {
            ans[i] = INT_MAX;
        }
    }

    while (!q.empty()) {
        int currentNode = q.top().second; // 작은 거 선택
        q.pop(); // 팝
        if (visit[currentNode]) continue; // 이미 방문이면
        visit[currentNode] = true;
        for (int i = 0; i < adj[currentNode].size(); ++i) {
            if (ans[adj[currentNode][i].second] > ans[currentNode] + adj[currentNode][i].first) {
                ans[adj[currentNode][i].second] = ans[currentNode] + adj[currentNode][i].first;
                q.push(edge(ans[adj[currentNode][i].second], adj[currentNode][i].second));
            }
        }
    }

    for (int i = 1; i <= V; ++i) {
        if (ans[i] == INT_MAX) {
            cout << "INF" << '\n';
        } else {
            cout << ans[i] << '\n';
        }
    }
}