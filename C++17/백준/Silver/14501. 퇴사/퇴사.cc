#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;

    vector<int> T(N + 1, 0); // i일에 시작하는 상담의 걸리는 시간
    vector<int> P(N + 1, 0); // i일에 시작하는 상담의 버는 금액
    for (int i = 1; i <= N; ++i) {
        int t, p;
        cin >> t >> p;
        T[i] = t;
        P[i] = p;
    }

    vector<int> D(N + 2, 0); // i번째날부터 퇴사일까지 벌 수 있는 최대 수익.
    D[N] = (T[N] == 1) ? P[N] : 0;
    for (int i = N - 1; i >= 1; --i) {
        if (T[i] + i - 1 <= N) D[i] = max(D[i + 1], D[i + T[i]] + P[i]);
        else D[i] = D[i + 1];
    }
    cout << D[1];
}