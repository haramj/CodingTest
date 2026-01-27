#include <iostream>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;

typedef tuple<int, int, int> edge; // s, e, w

struct compare {
    bool operator() (edge e1, edge e2) { // 가중치 오름차순으로.
        return get<2>(e1) > get<2>(e2);
    }
};

long long findFunc(vector<long long> &v, int n) {
    if (v[n] == n) return n;
    else {
        return v[n] = findFunc(v, v[n]);
    }
}

void unionFunc(vector<long long> &v, int n1, int n2) {
    int n1Top = findFunc(v, n1);
    int n2Top = findFunc(v, n2);
    if (n1Top != n2Top) {
        v[n1Top] = n2Top;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int V, E;
    cin >> V >> E;

    priority_queue<edge, vector<edge>, compare> edges;
    vector<long long> v(V + 1);

    // 유니온파인드 배열, 에지 리스트 초기화.
    for (int i = 1; i <= E; ++i) {
        int s, e, w;
        cin >> s >> e >> w;
        edges.push(edge(s, e, w));
    }

    for (int i = 1; i <= V; ++i) {
        v[i] = i;
    }

//    for (int i = 1; i <= E; ++i) { // 에지리스트 오름차순으로.
//        cout << get<2>(edges.top()) << ' ';
//        edges.pop();
//    }

    // V - 1 번 연결!!!!!!!!
    int answer = 0;
    int connectCount = 0;
    while (!edges.empty()) {
        edge cur = edges.top();
//        get<0>(cur) // 시작 노드
//        get<1>(cur) // 도착 노드
//        get<2>(cur) // 가중치
        edges.pop();
        if (findFunc(v, get<0>(cur)) != findFunc(v, get<1>(cur))) {
            unionFunc(v, get<0>(cur), get<1>(cur));
            connectCount++;
            answer += get<2>(cur);
            if (connectCount == V - 1) {
                break;
            }
        }
    }

    cout << answer;
}