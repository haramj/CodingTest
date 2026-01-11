#include <iostream>
#include <vector>

int main() {
    int N, M;
    std::cin >> N >> M;
    std::vector<int> v(N, 0);
    for (int i = 0; i < N; ++i) {
        std::cin >> v[i];
    }

    int maxValue = 0;
    for (int i = 0; i < N - 2; ++i) {
        for (int j = i + 1; j < N - 1; ++j) {
            for (int k = j + 1; k < N; ++k) {
                if (v[i] + v[j] + v[k] <= M && v[i] + v[j] + v[k] >= maxValue) {
                    maxValue = v[i] + v[j] + v[k];
                }
            }
        }
    }
    std::cout << maxValue;
}