#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;
    vector<vector<int>> D(N + 1, vector<int>(K + 1, 0)); // D[N][K] 는 NCK이다.
    D[1][0] = 1;
    D[1][1] = 1;
    for (int i = 2; i <= N; ++i) {
        for (int j = 0; j <= K; ++j) {
            D[i][j] = (D[i - 1][j] + D[i - 1][j - 1]) % 10007;
//            cout << i << " " << j << " " << D[i][j] << '\n';
        }
    }

    cout << D[N][K] % 10007;
    // D[i][j] = D[i - 1][j] + D[i - 1][j - 1];
    // 점화식을 알면 일단 i = 1 & j = 0, 1 일 때 값이 채워져 있어야 함.
    // D[1][0] = 1개 중에 0 개 뽑는 = 0;
    // D[1][1] = 1개 중에 1 개 뽑는 = 1;

}