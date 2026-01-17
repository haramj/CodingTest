// x좌표가 증가하는 순으로, 같으면 y좌표가 증가하는 순으로
#include <iostream>
#include <queue>
#include <utility>

struct compare {
    bool operator()(std::pair<int, int> p1, std::pair<int,int> p2) {
        if (p1.first == p2.first) {
            return p1.second > p2.second;
        } else {
            return p1.first > p2.first;
        }
    }
};

int main() {
    int N;
    std::cin >> N;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, compare> q;
    for (int i = 0; i < N; ++i) {
        std::pair<int, int> p;
        std::cin >> p.first >> p.second;
        q.push(p);
    }
    while (!q.empty()) {
        std::pair<int, int> temp = q.top();
        std::cout << temp.first << " " << temp.second << '\n';
        q.pop();
    }
}