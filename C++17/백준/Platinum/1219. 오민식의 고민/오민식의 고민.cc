// 에지 가중치는 음수. 도착 노드에서 값은 양수로 계산.
#include <iostream>
#include <vector>
#include <tuple>
#include <climits>

using namespace std;

typedef tuple<long long, long long, long long> edge;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int V, startVertex, endVertex, E;
    cin >> V >> startVertex >> endVertex >> E;
    vector<edge> edges;
    vector<long long> earn(V);
    vector<long long> ans(V);

    for (int i = 1; i <= E; ++i) {
        int s, e, w;
        cin >> s >> e >> w;
        edges.push_back(edge(s, e, w));
    }

    for (int i = 0; i < V; ++i) {
        cin >> earn[i]; // (도시번호) -> 도시에서 버는 돈.
    }

    for (int i = 0; i < V; ++i) {
        if (i == startVertex) ans[i] = - earn[i];
        else ans[i] = LLONG_MAX;
    }

    for (int i = 0; i < V - 1; ++i) { // 노드개수 - 1 만큼 에지사이클을 반복.
        for (int j = 0; j < edges.size(); ++j) {
            // earn[get<1>(edges[j])] 도착노드에서 버는 돈
            // get<0>(edges[j]) 현재 에지 시작노드
            // get<1>(edges[j]) 현재 에지 도착노드
            // get<2>(edges[j]) 현재 에지 비용
            // get<2>(edges[j]) - earn[get<1>(edges[j])] +  => 얘를 정답배열에 채워서 최솟값으로! -> 최솟값에 마지막에 음수 곱.
            if (ans[get<0>(edges[j])] != LLONG_MAX && ans[get<1>(edges[j])] > get<2>(edges[j]) + ans[get<0>(edges[j])] - earn[get<1>(edges[j])]) {
                ans[get<1>(edges[j])] = get<2>(edges[j]) + ans[get<0>(edges[j])] - earn[get<1>(edges[j])];
            }
        }
    }

    if (ans[endVertex] == LLONG_MAX) {
        cout << "gg";
        return 0;
    }

    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < edges.size(); ++j) {
            // earn[get<1>(edges[j])] 도착노드에서 버는 돈
            // get<0>(edges[j]) 현재 에지 시작노드
            // get<1>(edges[j]) 현재 에지 도착노드
            // get<2>(edges[j]) 현재 에지 비용
            // get<2>(edges[j]) - earn[get<1>(edges[j])] +  => 얘를 정답배열에 채워서 최솟값으로! -> 최솟값에 마지막에 음수 곱.
            if (ans[get<0>(edges[j])] != LLONG_MAX && ans[get<1>(edges[j])] > get<2>(edges[j]) + ans[get<0>(edges[j])] - earn[get<1>(edges[j])]) {
                ans[get<1>(edges[j])] = -2e18;
            }
        }
    }

    if (ans[endVertex] == -2e18) {
        cout << "Gee";
    }else {
        cout << (-1) * ans[endVertex];
    }
}