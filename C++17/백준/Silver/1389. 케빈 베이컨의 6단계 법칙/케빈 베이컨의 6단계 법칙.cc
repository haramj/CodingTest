#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

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
        int s, e;
        cin >> s >> e;
        D[s][e] = 1;
        D[e][s] = 1;
    }

    for (int k = 1; k <= V; ++k) {
        for (int s = 1; s <= V; ++s) {
            for (int e = 1; e <= V; ++e) {
                D[s][e] = min(D[s][e], D[s][k] + D[k][e]);
            }
        }
    }

    vector<int> ans(V + 1);

    for (int i = 1; i <= V; ++i) {
        int tempSum = 0;
        for (int j = 1; j <= V; ++j) {
            tempSum += D[i][j];
        }
        ans[i] = tempSum;
    }

    int minValue = ans[1];
    for (int i = 2; i <= V; ++i) {
        if (minValue > ans[i]) minValue = ans[i];
    }

    for (int i = 1; i <= V; ++i) {
        if (minValue == ans[i]) {
            cout << i;
            break;
        }
    }
}