#include <iostream>
#include <vector>
#include <cmath>
#include <tuple>
#include <queue>

using namespace std;

typedef tuple<int, int, int> Node; // 0 노드값 1 부모노드값 2 깊이

void LCA(int v1, int v2, int maxK, const vector<vector<int>> &P, const vector<vector<int>> &tree) {
    // 깊이 맞추기
    int depthInterval;
    int k;
    depthInterval = (tree[v1][1] - tree[v2][1] >= 0) ? tree[v1][1] - tree[v2][1] : -1 * (tree[v1][1] - tree[v2][1]);
    int t = 0;
    while (depthInterval) {
        if (depthInterval & 1) {
            if (tree[v1][1] > tree[v2][1]) { // v1이 더 깊음
                v1 = P[t][v1];
            } else if (tree[v1][1] < tree[v2][1]) {
                v2 = P[t][v2];
            } else {
                break;
            }
        }
        t++;
        depthInterval = (depthInterval >> 1); // 한칸씩 오른쪽으로 계속 !!
    } // 깊이 같아짐.

    // 최소공통조상 찾기
    // k값을 1씩 감소 && 최초로 두 노드의 부모가 달라질 때까지 반복 후 이동. && k가 0이 될 때까지 반복.
    k = maxK;
    while (k >= 0) { // 현재 트리 깊이 >= 2^k 일 때.
        if (tree[v1][1] >= pow(2, k) && P[k][v1] != P[k][v2]) {
            v1 = P[k][v1];
            v2 = P[k][v2];
        }
        k--;
    }

    if (v1 == v2) cout << v1 << '\n';
    else cout << P[0][v1] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<vector<int>> adj(N + 1);
    for (int i = 1; i <= N - 1; ++i) {
        int v1, v2;
        cin >> v1 >> v2;
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
    }

    queue<Node> q;
    vector<bool> visited(N + 1);
    vector<vector<int>> tree(N + 1, vector<int>(2, 0)); // 0 부모노드 1 깊이
    q.push(Node(1, 0, 1));
    int depth = 0;

    while (!q.empty()) {
        Node cur = q.front();
        q.pop();
        tree[get<0>(cur)] = {get<1>(cur), get<2>(cur)};
        if (depth < get<2>(cur)) {
            depth = get<2>(cur);
        }
        if (visited[get<0>(cur)]) continue;
        visited[get<0>(cur)] = true;
        for (int i = 0; i < adj[get<0>(cur)].size(); ++i) {
            if (!visited[adj[get<0>(cur)][i]]) {
                // adj[get<0>(cur)][i] 다음 노드
                q.push(Node(adj[get<0>(cur)][i], get<0>(cur), get<2>(cur) + 1)); //0 노드값 1 부모노드값 2 깊이
            }
        }
    }

//    for (int i = 1; i <= N; ++i) {
//        cout << i << " " << tree[i][0] << " " << tree[i][1] << '\n';
//    }

    int maxK = 0;
    while (pow(2, maxK) < depth) maxK++;
    vector<vector<int>> P(maxK + 1, vector<int>(N + 1, 0));
    for (int i = 1; i <= N; ++i) {
        P[0][i] = tree[i][0]; // k==0일때 i의 1번째 부모노드.
    }

    for (int i = 1; i < maxK; ++i) {
        for (int j = 1; j <= N; ++j) {
            P[i][j] = P[i - 1][P[i - 1][j]];
        }
    }

    int M;
    cin >> M;
    for (int i = 1; i <= M; ++i) {
        int v1, v2;
        cin >> v1 >> v2;
        LCA(v1, v2, maxK, P, tree);
    }
}