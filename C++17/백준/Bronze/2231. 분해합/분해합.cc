// 분해합
// 245의 분해합 = (245 + 2 + 4 + 5) = 256
// 256의 생성자 = 245의 분해합이 =256이므로.
// 216의 생성자 = 198 + 1 + 9 + 8
#include <iostream>
#include <cmath>

int main() {

    int N;
    std::cin >> N;

    int div = N;
    int length = 0; // 자리 수.

    while (div >= 1) {
        div /= 10;
        length++;
    }

    if (length == 1) {
        std::cout << N / 2;
        return 0;
    }


    for (int i = pow(10,length - 2); i <= pow(10,length); ++i) {
        int temp = i;
        int sum = 0;
        while (temp >= 1) {
            sum += temp % 10;
            temp /= 10;
        }
        if (sum + i == N) {
            std::cout << i;
            return 0;
        }
    }
    std::cout << 0;
    return 0;
}
