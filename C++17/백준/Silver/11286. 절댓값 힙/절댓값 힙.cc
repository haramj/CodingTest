// 우선순위 큐 문제
// 정렬을 구현체로 커스텀 하는 법.

#include <iostream>
#include <queue>
#include <vector>

struct compare {
    bool operator()(int o1, int o2) {
        int first_abs = abs(o1);
        int second_abs = abs(o2);
        if (first_abs == second_abs) {
            return o1 > o2;
        } else {
            return first_abs > second_abs;
        }
    }
};

int main() {
    int N;
    std::cin >> N;

    std::priority_queue<int, std::vector<int>, compare> q;

    for (int i = 0; i < N; ++i) {
        int temp;
        std::cin >> temp;
        if (temp) { // 입력
            q.push(temp);
        } else { // 가장 절댓값 작은 값. 출력 및 제거.
            if (q.empty()) {
                std::cout << '0' << '\n';
            } else {
                std::cout << q.top() << '\n';
                q.pop();
            }
        }
    }
}