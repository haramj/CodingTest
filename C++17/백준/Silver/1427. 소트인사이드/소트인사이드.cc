#include <iostream>
#include <vector>

int main() {

    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::string s;
    std::cin >> s;
    int N = s.size();

    std::vector<int> v(N, 0);
    for (int i = 0; i < N; ++i) {
        v[i] = std::stoi(s.substr(i,1));
    }

    for (int i = 0; i < N - 1; ++i) {
        for (int j = i + 1; j < N; ++j) {
            if (v[i] < v[j]) {
                int temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }
        }
    }

    std::string answer = "";
    for (int i = 0; i < N; ++i) {
        answer += v[i] + '0';
    }

    std::cout << answer;
}