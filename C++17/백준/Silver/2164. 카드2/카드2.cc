#include <iostream>
#include <queue>

int main() {
    int N;
    std::cin >> N;

    std::queue<int> q;
    for (int i = 1; i < N + 1; ++i) {
        q.push(i);
    }

    while (q.size() > 1) {
        q.pop();
        if (q.size() == 1){
            break;
        }
        int temp = q.front();
        q.pop();
        q.push(temp);
    }

    std::cout << q.front();
}