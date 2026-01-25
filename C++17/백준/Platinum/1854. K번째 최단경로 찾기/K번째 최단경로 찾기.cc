// k번째를 구하기 위해 최대힙 사용해서 다익스트라 배열에 넣는데,
// visitCount 배열로 이를 컨트롤한다.
#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <climits>

using namespace std;

typedef pair<int, int> edge;
typedef priority_queue<int> maxHeap; // ans 배열에 값으로 사용. ans[i].top() 은 k번째 최단경로

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int V, E, K;
    cin >> V >> E >> K;

    vector<int> visitCount(V + 1);
    vector<maxHeap> ans(V + 1);
    vector<vector<edge>> adj(V + 1);
    priority_queue<edge, vector<edge>, greater<edge>> priQue; // 알고리즘용 q로 사용.

    for (int i = 1; i <= V; ++i) {
        visitCount[i] = 0;
    }

    maxHeap tempMaxHeap;
    tempMaxHeap.push(0);
    ans[1] = tempMaxHeap;
    for (int i = 2; i <= V; ++i) {
        maxHeap temp;
        temp.push(INT_MAX);
        ans[i] = temp;
    }

    for (int i = 1; i <= E; ++i) {
        int v1, v2, value;
        cin >> v1 >> v2 >> value;
        adj[v1].push_back(edge(value, v2));
    }

    priQue.push(edge(0, 1));

    while (!priQue.empty()) {
        int curDistance = priQue.top().first;
        int curNode = priQue.top().second;
        priQue.pop();
        if (visitCount[curNode] >= K) continue;
        visitCount[curNode]++;

        for (int i = 0; i < adj[curNode].size(); ++i) {
            int curToNextDistance = adj[curNode][i].first;
            int nextNode = adj[curNode][i].second;
            if (ans[nextNode].size() < K) {
                if (ans[nextNode].top() == INT_MAX) ans[nextNode].pop();
                ans[nextNode].push(curToNextDistance + curDistance);
                priQue.push(edge(curToNextDistance + curDistance, nextNode));
            } else {
                if (curToNextDistance + curDistance < ans[nextNode].top()) {
                    ans[nextNode].pop();
                    ans[nextNode].push(curToNextDistance + curDistance);
                    priQue.push(edge(curToNextDistance + curDistance, nextNode));
                }
            }
        }
    }

    for (int i = 1; i <= V; ++i) {
        if (ans[i].size() >= K) {
            cout << ans[i].top() << '\n';
        } else {
            cout << -1 << '\n';
        }
    }
}