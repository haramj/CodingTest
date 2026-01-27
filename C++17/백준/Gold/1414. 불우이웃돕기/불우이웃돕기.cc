#include <iostream>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;

typedef tuple<int, int, int> edge; // s, e, w

struct compare {
    bool operator() (edge e1, edge e2) {
        return get<2>(e1) > get<2>(e2);
    }
};

int findFunc(vector<int> &v, int n) {
    if (v[n] == n) return n;
    else return v[n] = findFunc(v, v[n]);
}

void unionFunc(vector<int> &v, int n1, int n2) {
    int n1Top = findFunc(v, n1);
    int n2Top = findFunc(v, n2);
    if (n1Top != n2Top) v[n1Top] = n2Top;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // a ~ z 97 ~ 122 => 1  ~ 26 : (-96)
    // A ~ Z 65 ~ 90  => 27 ~ 52 : (-38)
    int V;
    cin >> V;

    priority_queue<edge, vector<edge>, compare> edges;
    vector<int> v(V + 1);

    for (int i = 1; i <= V; ++i) {
        v[i] = i;
    }

    int maxLen = 0;

    for (int i = 1; i <= V; ++i) {
        char t[V];
        cin >> t;
        for (int j = 1; j <= V; ++j) {
            if (t[j - 1] == '0') {
                edges.push(edge(i, j, 0));
            } else {
                int intTemp = t[j - 1];
                if (intTemp >= 97 && intTemp <= 122) { // 소문자
                    intTemp -= 96;
                } else if (intTemp >= 65 && intTemp <= 90) { // 대문자
                    intTemp -= 38;
                }
                edges.push(edge(i, j, intTemp));
                maxLen += intTemp;
            }
        }
    }

    if (V == 1) {
        cout << get<2>(edges.top());
        return 0;
    }

    int connectCount = 0;
    int answer = 0;

    bool g = false;
    while (!edges.empty()) {
        int curStart = get<0>(edges.top());
        int curEnd = get<1>(edges.top());
        int curWeight = get<2>(edges.top());
        edges.pop();
        if (!curWeight) continue;
        if (findFunc(v, curStart) != findFunc(v, curEnd)) {
            unionFunc(v, curStart, curEnd);
            connectCount++;
            answer += curWeight;
            if (connectCount == V - 1) {
                g = true;
                break;
            }
        }
    }

    if (g) cout << maxLen - answer;
    else cout << -1;
}