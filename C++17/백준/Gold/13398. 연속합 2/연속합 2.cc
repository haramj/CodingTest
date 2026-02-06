// 연속합.
// 하나를 제거해도 되니까
// 왼쪽에서 봤을 때 i까지 최대 연속합
// 오른쪽에서 봤을 때 i까지 최대 연속합
// 이후 각자 더한 것으로 하는 아이디어 !!! 하나 이기 때문에 가능.!!!!
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

    vector<long long> v(N + 1, 0);
    for (int i = 1; i <= N; ++i) {
        cin >> v[i];
    }

    vector<long long> L(N + 2, 0); // 왼쪽에서 봤을 때 i번째를 포함하는 i까지 최대 연속합
    vector<long long> R(N + 2, 0); // 오른쪽에서 봤을 때 i번째를 포함하는 i까지 최대 연속합

    L[1] = v[1];
    R[N] = v[N];
    int r = N + 1;
    for (int i = 2; i <= N; ++i) {
        L[i] = max(v[i], L[i - 1] + v[i]);
        R[r - i] = max(v[r - i], R[r - i + 1] + v[r - i]);
    }
//    for (int i = 1; i <= N; ++i) {
//        cout << L[i] << ' ';
//    } cout << '\n';
//    for (int i = 1; i <= N; ++i) {
//        cout << R[i] << ' ';
//    } cout << '\n';

    vector<long long> result(N + 2, 0);
    result[1] = L[1];
    for (int i = 2; i <= N; ++i) {
        result[i] = max(result[i - 1], max(L[i - 1] + R[i + 1], L[i]));
    }
    cout << result[N];
}