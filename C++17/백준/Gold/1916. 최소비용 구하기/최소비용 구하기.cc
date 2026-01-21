#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;
typedef pair<int, int> edge; // 거리, 노드번호

int main() {
    int V, E;
    cin >> V >> E;
    vector<vector<edge>> adj(V + 1);
    vector<bool> visit(V + 1);
    vector<int> ans(V + 1);
    priority_queue<edge, vector<edge>, greater<edge>> q;

    for (int i = 1; i <= E; ++i) {
        int s, e, w;
        cin >> s >> e >> w;
        adj[s].push_back(edge(w, e));
    }
    int startVertex, endVertex;
    cin >> startVertex >> endVertex;

    for (int i = 1; i <= V; ++i) {
        if (i == startVertex) {
            ans[i] = 0;
            q.push(edge(0, i));
        } else {
            ans[i] = INT_MAX;
        }
    }

    while (!q.empty()) {
//        for(int i = 1; i <= V; ++i) {
//            cout << ans[i] << ' ';
//        } cout << '\n';
        int currentNode = q.top().second;
        q.pop();
        if (visit[currentNode]) continue;
        visit[currentNode] = true;

        for (int i = 0; i < adj[currentNode].size(); ++i) {
//            cout << i << " ";
            // adj[currentNode][i].first 다음노드 가는 거리
            // adj[currentNode][i].second 다음노드 번호
            // 현재까지최단거리 + 다음노드가는거리 < 다음노드까지가는최단거리
            if(adj[currentNode][i].first + ans[currentNode] < ans[adj[currentNode][i].second]) {
                ans[adj[currentNode][i].second] = adj[currentNode][i].first + ans[currentNode];
                q.push(edge(ans[adj[currentNode][i].second], adj[currentNode][i].second));
            }
        } //cout << '\n';
    }

    cout << ans[endVertex];
}