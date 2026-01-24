#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <climits>

using namespace std;
typedef pair<int, int> edge;
typedef priority_queue<int> que;

// 최소힙이 아니라 .. 최대힙으로 넣어서 K번까지만 노드에 방문하게 한 후, 탑을 리턴하자.

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int V, E, K;
    cin >> V >> E >> K;

    vector<vector<edge>> adj(V + 1);
    vector<que> dijkstra(V + 1); // 나중에 k번째니까 바꿔야 함.
//    vector<bool> visit(V + 1, false); => 방문 여부로만 말고, 방문횟수 카운드를 하자.
    vector<int> visitCount(V + 1, 0);
    priority_queue<edge, vector<edge>, greater<edge>> q;

    for (int i = 1; i <= E; ++i) {
        int v1, v2, d;
        cin >> v1 >> v2 >> d;
        edge temp = edge(d,v2);
        adj[v1].push_back(temp);
    }

    que firstQ;
    firstQ.push(0);
    dijkstra[1] = firstQ;
    q.push(edge(0, 1));

    for (int i = 2; i <= V; ++i) {
        que Q;
        Q.push(INT_MAX);
        dijkstra[i] = Q;
    }

    while (!q.empty()) {
//        for (int i = 1; i <= V; ++i) {
//            cout << dijkstra[i].top() << ' ';
//        } cout << '\n';

        int curNodeNumber = q.top().second;
        int curDistance = q.top().first;

        visitCount[curNodeNumber]++;
        q.pop();

        for (int i = 0; i < adj[curNodeNumber].size(); ++i) {
            int nextNodeNumber = adj[curNodeNumber][i].second;
            int curToNextDistance = adj[curNodeNumber][i].first;
            if (dijkstra[nextNodeNumber].size() < K) {
                // 무조건 추가.
                if (dijkstra[nextNodeNumber].top() == INT_MAX)
                    dijkstra[nextNodeNumber].pop();
                q.push(edge(curDistance + curToNextDistance, nextNodeNumber));
                dijkstra[nextNodeNumber].push(curDistance + curToNextDistance);
            } else {
                if (curDistance + curToNextDistance < dijkstra[nextNodeNumber].top()) {
                    dijkstra[nextNodeNumber].pop();
                    dijkstra[nextNodeNumber].push(curDistance + curToNextDistance);
                    q.push(edge(curDistance + curToNextDistance, nextNodeNumber));
                }
            }

        }
    }

    for (int i = 1; i <= V; ++i) {
        if (visitCount[i] >= K) {
            cout << dijkstra[i].top() << '\n';
        } else {
            cout << -1 << '\n';
        }
    }
}