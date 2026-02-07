#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;
    vector<vector<int>> v(N + 1, vector<int>(M + 1, 0));

    for (int i = 1; i <= N; ++i) {
        string input;
        cin >> input;
        for (int j = 1; j <= M; ++j) {
            v[i][j] = input[j - 1] - '0';
        }
    }

    vector<vector<int>> D(N + 1, vector<int>(M + 1, 0));
    int maxLength = 0;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            if (D[i - 1][j] && D[i][j - 1] && D[i - 1][j - 1]) {
                if (v[i][j]) {
                    D[i][j] = min(D[i - 1][j], min(D[i][j - 1], D[i - 1][j - 1])) + 1;
                    if (maxLength < D[i][j]) maxLength = D[i][j];
                }
            } else {
                if (v[i][j]) {
                    D[i][j] = 1;
                    if (maxLength < D[i][j]) maxLength = D[i][j];
                }
            }
        }
    }

    cout << maxLength * maxLength;
}