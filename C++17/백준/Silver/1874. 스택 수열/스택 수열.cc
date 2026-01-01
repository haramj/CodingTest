#include <iostream>
#include <vector>
#include <stack>

int main() {

    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N;
    std::stack<int> s;
    std::string answer = "";

    std::cin >> N;

    std::vector<int> v(N + 1);
    for (int i = 1; i < N + 1; ++i) {
        std::cin >> v[i]; // v = [0, 4, 3, 6, 8, 7, 5, 2, 1]
    }

    int i = 1; // 현재 push를 계속 오름차순으로 하다가 만일 현재 수열에 해당되는 값이 나오면 pop을 한다.
    int j = 1;
    while (j <= N) {
        if (i > N && s.top() != v[j]) {
            break;
        }
        if (!s.empty() && s.top() == v[j]) {
            s.pop();
            ++j;
            answer += "-";
        } else {
            s.push(i);
            ++i;
            answer += "+";
        }
    }

    if (!s.empty()) {
        std::cout << "NO";
    }
    else {
        for (int i = 0; i < N * 2 - 1; ++i) {
            std::cout << answer[i] << '\n';
        }
        std::cout << answer[N * 2 - 1];
    }

    // push 하는 순서는 반드시 오름차순
    // 임의의 수열이 주어졌을 때, 스택을 이용해 그 수열을 만들 수 있는지 / 없는지 . 있으면 push / pop 연산을 수행해야 하는지.
    return 0;
}