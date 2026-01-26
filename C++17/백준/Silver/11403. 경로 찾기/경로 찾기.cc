#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int V;
    cin >> V;

    vector<vector<long long>> D(V);
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            int temp;
            cin >> temp;
            if (temp) D[i].push_back(temp);
            else D[i].push_back(INT_MAX);
        }
    }

    for (int k = 0; k < V; ++k) {
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                if (D[i][k] == INT_MAX && D[k][j] == INT_MAX) continue;
                D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
            }
        }
    }

    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            if (D[i][j] == INT_MAX) cout << 0 << " ";
            else {
                if (D[i][j]) cout << 1 << " ";
            }
        } cout << '\n';
    }
}