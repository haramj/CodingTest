#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // 애초에 pair 로 값, 인덱스로 저장.
    // 후에 정렬하면 알아서 first 기준으로 정렬하고.
    // 그때, 인덱스랑 second의 차이가 가장 큰 애가 이동 가장 많이 한 애임.

    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N;
    std::cin >> N;

    std::vector<std::pair<int, int>> v(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> v[i].first;
        v[i].second = i;
    }

    std::sort(v.begin(), v.end());

    int maxValue = v[0].second - 0;
    for (int i = 1; i < N; ++i) {
        if (maxValue < v[i].second - i) {
            maxValue = v[i].second - i;
        }
    }

    std::cout << maxValue + 1 << '\n';
}