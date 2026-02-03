#include <iostream>
#include <vector>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
#endif
    cout.precision(10);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long N = 0, M; // 조약돌 개수 / 색 개수
    cin >> M;
    vector<long long> color(M + 1, 0);
    for (int i = 1; i <= M; ++i) {
        cin >> color[i];
        N += color[i];
    }
    int k; // k 개 선택.
    cin >> k;

    // 조합 DP 배열 값 채우기 먼저.!!! // n개 w중에
    double answer = 0;
    for (int i = 1; i <= M; ++i) {
        if (color[i] < k) continue; // k개보다 적으면 확률은 0

        double temp = 1.0;
        for (int j = 0; j < k; ++j) {
            temp *= (double)(color[i] - j) / (double)(N - j);
        }
        answer += temp;
    }
    cout << answer;
}