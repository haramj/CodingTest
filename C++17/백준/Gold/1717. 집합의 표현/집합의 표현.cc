#include <iostream>
#include <vector>

void unionFunc(std::vector<int> &v, int a, int b) { // a를 b의 대표노드로.
    if (a == v[a] && b == v[b]) {
        v[b] = a;
        return;
    }
    if (a != v[a]) {
        unionFunc(v, v[a], b);
    }
    if (b != v[b]) {
        unionFunc(v, a, v[b]);
    }
}

int findFuncRecur(std::vector<int> &v, int n1) {
    if (v[n1] == n1) {
        return n1;
    } else {
        v[n1] = findFuncRecur(v, v[n1]);
        return v[n1];
    }
}

void findFunc(std::vector<int> &v, int a, int b) { // a와 b가 같은 집합인지 확인. => 그냥 최상위루트가 같은지.
    if (findFuncRecur(v,a) == findFuncRecur(v,b)) {
        std::cout << "YES" << '\n';
        return;
    }
    std::cout << "NO" << '\n';
}

int main() {
    
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int N, M; // 집합수 / 질의수
    std::cin >> N >> M;
    std::vector<int> v(N + 1);
    for (int i = 0; i <= N; ++i) {
        v[i] = i; // 각 노드의 대표노드를 본인으로.
    }

    for (int i = 0; i < M; ++i) {
        int unionOrFind, a, b;
        std::cin >> unionOrFind >> a >> b;
        if (unionOrFind == 0) { // union 연산
            unionFunc(v, a, b);
        } else { // find 연산
            findFunc(v, a, b);
        }
//        for (int j = 0; j <= N; ++j) {
//            std::cout << j << " ";
//        } std::cout << '\n';
//        for (int j = 0; j <= N; ++j) {
//            std::cout << v[j] << " ";
//        } std::cout << '\n';
//        std::cout << '\n';
    }
}