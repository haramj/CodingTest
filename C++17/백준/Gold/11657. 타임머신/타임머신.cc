#include <iostream>
#include <vector>
#include <climits>
#include <tuple>

using namespace std;

typedef tuple<int, int, int> edge;

int main() {
    int V, E;
    cin >> V >> E;
    vector<long long> ans(V + 1);
    vector<edge> edges;

    for (int i = 1; i <= E; ++i) {
        int s, e, w;
        cin >> s >> e >> w;
        edges.push_back(edge(s, e, w));
    }

    ans[1] = 0;
    for (int i = 2; i <= V; ++i) {
        ans[i] = INT_MAX;
    }

    for (int i = 1; i <= V - 1; ++i) {
        for (int j = 0; j < E; ++j) {
            // get<0>(edge[j]) 현재 엣지의 시작
            // get<1>(edge[j]) 현재 엣지의 끝
            // get<2>(edge[j]) 현재 엣지의 시간
            if (ans[get<0>(edges[j])] != INT_MAX && ans[get<1>(edges[j])] > ans[get<0>(edges[j])] + get<2>(edges[j])) {
                ans[get<1>(edges[j])] = ans[get<0>(edges[j])] + get<2>(edges[j]);
            }
        }
    }

    for (int j = 0; j < E; ++j) {
        // get<0>(edge[j]) 현재 엣지의 시작
        // get<1>(edge[j]) 현재 엣지의 끝
        // get<2>(edge[j]) 현재 엣지의 시간
        if (ans[get<0>(edges[j])] != INT_MAX && ans[get<1>(edges[j])] > ans[get<0>(edges[j])] + get<2>(edges[j])) {
            cout << -1 << '\n';
            return 0;
        }
    }

    for (int i = 2; i <= V; ++i) {
        if (ans[i] == INT_MAX) cout << -1 << '\n';
        else cout << ans[i] << '\n';
    }
}