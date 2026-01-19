#include <iostream>
#include <vector>

int findFunc(std::vector<int> &v, int n) {
    if (v[n] != n) {
        v[n] = findFunc(v,v[n]);
        return v[n];
    } else {
        return n;
    }
}

void unionFunc(std::vector<int> &v, int a, int b) {
    int aTop = findFunc(v, a);
    int bTop = findFunc(v, b);
    if (aTop != bTop){
        v[aTop] = bTop;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N, M; // 도시수, 여행하는도시수
    std::cin >> N >> M;
    std::vector<int> v(N + 1, 0);

    for (int i = 1; i <= N; ++i) {
        v[i] = i;
    }

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            int temp;
            std::cin >> temp;
            if (temp && i <= j) {
                unionFunc(v, i, j);
                // i 번이랑 j 번 연결. UNION 연산.
            }
        }
    }

    int ans;
    for (int i = 0; i < M; ++i) {
        int temp;
        std::cin >> temp;
        int cur = findFunc(v, temp);
//        std::cout << cur << ' ';
        if (!i){
            ans = cur;
        } else {
            if (ans != cur) {
                std::cout << "NO";
                return 0;
            }
        }
    }
    std::cout << "YES";
}