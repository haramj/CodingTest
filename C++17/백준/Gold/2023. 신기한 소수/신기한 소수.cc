#include <iostream>
#include <vector>

bool isPrime(int n) {
    if (n == 1) return false;
    if (n == 2) return true;
    for (int i = 2; i <= n/2+1; ++i) {
        if (n % i == 0) return false;
    } return true;
}

void DFS(int x, int loc, int maxLen) { // 1이면 첫자리 4면 4자리 전체 다
    if (loc > maxLen) return;
    if (isPrime(x)) {
        if (loc == maxLen) std::cout << x << '\n';
        else {
            DFS(10*x + 1, loc+1, maxLen);
            DFS(10*x + 3, loc+1, maxLen);
            DFS(10*x + 5, loc+1, maxLen);
            DFS(10*x + 7, loc+1, maxLen);
            DFS(10*x + 9, loc+1, maxLen);
        }
    }
}

int main() {
    int N;
    std::cin >> N;
    std::vector<int> v(4);
    v[0] = 2;
    v[1] = 3;
    v[2] = 5;
    v[3] = 7;
    for (int i = 0; i < 4; ++i) {
        DFS(v[i], 1, N);
    }
}