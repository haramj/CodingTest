// 18 = 5 + 5 + 3
#include <iostream>

int main() {

    int N;
    std::cin >> N;
    int answer = 0;

    while (N >= 0) {
        if (N%5 == 0) {
            std::cout << answer + N/5;
            return 0;
        }
        N -= 3;
        answer++;
    }

    if (N < 0) {
        std::cout << -1;
        return 0;
    }
}