#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int main() {
    int V, E;
    cin >> V >> E;
    vector<vector<long long>> D(V + 1);

    for (int i = 1; i <= V; ++i) {
        D[i].push_back(0);
        for (int j = 1; j <= V; ++j) {
            if (i == j) D[i].push_back(0);
            else D[i].push_back(INT_MAX);
        }
    }

    for (int i = 1; i <= E; ++i) {
        int s, e, w;
        cin >> s >> e >> w;
        if (D[s][e] > w) D[s][e] = w;
    }

    for (int k = 1; k <= V; ++k) {
        for (int s = 1; s <= V; ++s) {
            for (int e = 1; e <= V; ++e) {
                D[s][e] = min(D[s][e], D[s][k] + D[k][e]);
            }
        }
    }

    for (int i = 1; i <= V; ++i) {
        for (int j = 1; j <= V; ++j) {
            if (D[i][j] == INT_MAX) {
                cout << 0 << " ";
            } else cout << D[i][j] << " ";
        } cout << '\n';
    }
}