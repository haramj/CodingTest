// 길이가 N인 정수 배열 A와 B가 있을 때 S = A[0] * B[0] + ... + A[N-1] * B[N-1]
// S의 최소를 구하기 위해 A를 재배열하여 S의 최솟값을 구하라.
// 1 1 1 6 0 가장 작은 A를 가장 큰 B에 곱해지게.
// A는 오름차순, B도 오름차순으로 우선 정렬 시키고 A를 순회하면서 B의 역순으로 순회하며 곱하도록.

#include <vector>
#include <iostream>
#include <algorithm>

int main() {

    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N;
    std::cin >> N;

    std::vector<int> A(N, 0);
    std::vector<int> B(N, 0);
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i];
    }
    for (int i = 0; i < N; ++i) {
        std::cin >> B[i];
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int answer = 0;
    for(int i = 0; i < N; ++i) {
        answer += A[i] * B[N - 1 - i];
    }
    std::cout << answer;
}
