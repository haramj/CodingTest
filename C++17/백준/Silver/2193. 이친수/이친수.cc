//N(1 ≤ N ≤ 90)이 주어졌을 때, N자리 이친수의 개수
// D[i] i자리 이친수의 최대 개수
// D[1] 1자리 이친수의 최대 개수 1(1) (0 안 됨. 조건 위배.)
// D[2] 2자리 이친수의 최대 개수 1(10) (11 안됨 01 안됨 조건 위배.)
// D[3] 3자리 이친수의 최대 개수 2(100, 101)
// D[4] 4자리 이친수의 최대 개수 3(1000, 1001, 1010)
// D[5] 5자리 이친수의 최대 개수 5(10001, 10010, 10101, 10100, 10000)
#include <iostream>
#include <vector>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long N;
    cin >> N;
    vector<long long> D(N + 1, 0);
    D[1] = 1;
    D[2] = 1;
    for (long long i = 3; i <= N; ++i) {
        D[i] = D[i - 1] + D[i - 2];
    }
    cout << D[N];

}