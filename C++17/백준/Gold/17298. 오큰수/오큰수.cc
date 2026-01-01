#include <iostream>
#include <stack>
#include <vector>
#include <string>

int main() {
#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
#endif

    // 이 문제에선 스택에 배열 인덱스값을 추가한다.
    int N;
    std::cin >> N;

    std::stack<int> s;
    std::vector<int> v(N + 1, 0);
    std::vector<int> answer(N + 1, -1);

    for (int i = 0; i < N; ++i) {
        std::cin >> v[i];
    }

    s.push(0);
    for (int i = 0; i < N; ++i){
        while (!s.empty() && v[s.top()] < v[i]) {
            answer[s.top()] = v[i];
            s.pop();
        }
        s.push(i);
    }

    for (int i = 0; i < N; ++i) {
        std::cout << answer[i] << " ";
    }
}