#include <iostream>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N, M; // 세로 N 가로 M
    std::cin >> N >> M;
    std::vector<std::vector<int>> v(N);
    for (int i = 0; i < N; ++i) {
        std::string temp;
        std::cin >> temp;
        for (int j = 0; j < M; ++j) {
            int t = temp[j] - '0';
            v[i].push_back(t);
        }
    }

    int maxLength = (N >= M) ? M : N; // 3
    int answer = 1;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            for (int k = 1; k < maxLength; ++k) {
                if (i + k < N && j + k < M && v[i][j] == v[i + k][j] && v[i][j] == v[i][j + k] && v[i][j] == v[i + k][j + k]) {
                    if (answer < (k + 1) * (k + 1)) {
                        answer = (k + 1) * (k + 1);
                    }
                }
            }
        }
    }
    std::cout << answer;
}