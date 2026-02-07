#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, l, r;
    cin >> N >> l >> r;

    vector<vector<vector<long long>>> D(N + 2, vector<vector<long long>>(l + 2, vector<long long>(r + 2, 0)));
    D[1][1][1] = 1;
    D[2][1][1] = 0;
    D[2][1][2] = 1;
    D[2][2][1] = 1;
    D[2][2][2] = 0;

    for (int i = 3; i <= N; ++i) {
        for (int j = 1; j <= l; ++j) {
            for (int k = 1; k <= r; ++k) {
                D[i][j][k] = (D[i - 1][j - 1][k] + D[i - 1][j][k - 1] + D[i - 1][j][k] * (i - 2)) % 1000000007;
            }
        }
    }

    cout << D[N][l][r] % 1000000007;
}