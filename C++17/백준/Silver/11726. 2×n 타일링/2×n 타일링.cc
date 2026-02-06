#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<long long> D(N + 1, 0);
    // D[i] 2 x i 크기 직사각형을 채우는 방법의 최대 수. = 2 x (i - 1) 크기 직사각형을 채우는 방법의 최대 수 + 2 x (i - 2) 크기 직사각형 채우는 방법의 수
    D[1] = 1;
    D[2] = 2;
    for (int i = 3; i <= N; ++i) {
        D[i] = (D[i - 1] + D[i - 2]) % 10007;
    }
    cout << D[N];
}