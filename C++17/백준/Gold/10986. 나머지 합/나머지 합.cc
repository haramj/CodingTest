#include <iostream>
#include <vector>

int main() {

    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N, M; // N개 입력, M으로 나누어 떨어져야 함.
    std::cin >> N >> M;
    int temp;
    long answer = 0;
    std::vector<long> s(N + 1, 0);
    std::vector<long> c(M + 1, 0);
    std::cin >> s[0];

    for (int i = 1; i < N; ++i) {
        std::cin >> temp;
        s[i] = temp + s[i - 1];
    }

    for (int i = 0; i < N; ++i) {
        int remainder = s[i] % M;
        if (remainder == 0) {
            answer++;
        }
        c[remainder]++;
    }

    for (int i = 0; i < M; ++i) {
        if (c[i] > 1) {
            answer += (c[i] * (c[i] - 1)) / 2;
        }
    }

    std::cout << answer << '\n';

    //    5 3
    //    1 2 3 1 2 => 1 3 6 7 9 => 1 0 0 1 0

    // (a + b) % c == ((a % c) + (b % c)) % c
    // => i부터 j까지의 합을 나눈 나머지 == i 부터 j까지 각각 나눈 나머지들의 합의 나머지
    // => 모든 구간합들의 항을 나눈 나머지로 정한다.
    // => sj%m 과 si%m이 같으면 (sj-si)%m 은 0이다. 따라서 각 뺀게 0이면 그 순서쌍은 만족.
    return 0;
}