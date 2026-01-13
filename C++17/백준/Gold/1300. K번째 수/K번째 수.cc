//1 2 3 -> 3개
//2 4 6 -> 2개
//3 6 9 -> 1개
// 중앙값 4
// 4보다 작거나 같은 거의 개수 총 6개. 7개일때까지 중앙값 조정.
//
//1, 2, 2, 3, 3, 4, "6", 6, 9
// 중앙값보다 작은 수의 개수가 k-1 일때까지 반복해 나가면서
// 이분탐색 진행.
//
#include <iostream>
#include <vector>

int main() {
    int N, k;
    std::cin >> N >> k;

    int s = 1;
    int e = k;
    int answer;
    while (s <= e) {
        int mid = (s + e) / 2;
        int count = 0;
        for (int i = 1; i <= N; ++i) {
            count += std::min(N, mid/i);
        }
        if (count < k) s = mid + 1;
        else {
            answer = mid;
            e = mid - 1;
        }
    }
    std::cout << answer;
}