// 각 n번째 줄은 n번집을 r g b 로 칠하는 비용이다.
#include <iostream>
#include <vector>
#include <algorithm>

// D[i] - i번째 집까지 칠했을 때 최소 비용.
// D[i] = D[i - 1] + 현재 RGB 중 최소 이면서 조건 만족.

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    int n0, n1, n2; // R G B
    vector<vector<int>> D(N + 1, vector<int>(3, 0)); // D[i][k] i번째집을 k로 칠했을 때 최소
    for (int i = 1; i <= N; ++i) {
        cin >> n0 >> n1 >> n2;
        if (i == 1) {
            D[1][0] = n0;
            D[1][1] = n1;
            D[1][2] = n2;
        } else {
            D[i][0] = min(D[i - 1][1], D[i - 1][2]) + n0;
            D[i][1] = min(D[i - 1][0], D[i - 1][2]) + n1;
            D[i][2] = min(D[i - 1][0], D[i - 1][1]) + n2;
        }
    }
    cout << min(D[N][0], min(D[N][1], D[N][2]));
    return 0;
}