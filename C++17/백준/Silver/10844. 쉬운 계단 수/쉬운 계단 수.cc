#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<vector<long long>> D(N + 1, vector<long long>(10));
    D[1][0] = 0;
    for (int i = 1; i <= 9; ++i) D[1][i] = 1;

    for (int i = 2; i <= N; ++i) {
        for (int j = 0; j <= 9; ++j) {
            if (j == 0) {
                D[i][j] = D[i - 1][j + 1] % 1000000000;
            } else if (j == 9) {
                D[i][j] = D[i - 1][j - 1];
            } else D[i][j] = (D[i - 1][j - 1] + D[i - 1][j + 1]) % 1000000000;
//            cout << D[i][j] << '\n';
        }
    }

    long long answer = 0;
    for (int i = 0; i <= 9; ++i) {
        answer += D[N][i];
    }
    cout << answer % 1000000000;
}