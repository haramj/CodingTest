#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    vector<int> parent(N);
    for (int i = 0; i < N; ++i) {
        cin >> parent[i];
    }
    int deleteNode;
    cin >> deleteNode;

    vector<vector<int>> adj(N);

    int root;

    for (int i = 0; i < N; ++i) {
        if (parent[i] == -1) { // 루트 노드.
            root = i;
            continue;
        }
        adj[parent[i]].push_back(i);
        adj[i].push_back(parent[i]);
    }

    //find deleteNode.

    if (root == deleteNode) {
        cout << 0;
        return 0;
    }

    queue<int> q;
    vector<bool> visit(N);
    int answer = 0;

    q.push(root);
    visit[root] = true;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        if (cur == deleteNode) {
            continue;
        }
        int childCount = 0;
        for (int i = 0; i < adj[cur].size(); ++i) {
            if (!visit[adj[cur][i]]) {
                if (adj[cur][i] == deleteNode) continue;
                visit[adj[cur][i]] = true;
                q.push(adj[cur][i]);
                childCount++;
            }
        }
        if (childCount == 0) {
            answer++;
        }
    }

    cout << answer;
}