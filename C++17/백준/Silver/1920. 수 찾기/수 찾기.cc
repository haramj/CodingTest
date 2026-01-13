//1 두번째 배열에 0번째인 1이 첫번째 배열에 있으니 1
//1 두번째 배열에 1번째인 3이 첫번째 배열에 있으니 1
//0 두번째 배열에 2번째인 7이 첫번째 배열에 없으니 0
//0 두번째 배열에 3번째인 9가 첫번째 배열에 없으니 0
//1 두번째 배열에 4번째인 5가 첫번째 배열에 있으니 1
// 이진탐색은 시작인덱스 / 종료인덱스로 구현 !!
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N, M;
    std::cin >> N;
    std::vector<int> v1(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> v1[i];
    }
    sort(v1.begin(), v1.end());
    std::cin >> M;
    std::vector<int> v2(M);
    for (int i = 0; i < M; ++i) {
        std::cin >> v2[i];
    }

    for (int i = 0; i < M; ++i) { // v2[i] // 지금 찾으려는 애.
        int s = 0;
        int e = N - 1;
        bool find = false;
        while (s <= e) { // 1 2 3 4 5
            int midIndex = (s + e) / 2;
            if (v1[midIndex] > v2[i]) {
                e = midIndex - 1;
            } else if (v1[midIndex] < v2[i]) {
                s = midIndex + 1;
            } else {
                std::cout << 1 << '\n';
                find = true;
                break;
            }
        }
        if (!find) {
            std::cout << 0 << '\n';
        }
    }
}