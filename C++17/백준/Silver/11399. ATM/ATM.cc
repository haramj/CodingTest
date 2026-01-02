#include <iostream>
#include <vector>

int main() {
#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
#endif

    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N;
    std::cin >> N;
    std::vector<int> v(N, 0);
    std::vector<int> s(N, 0);

    for (int i = 0; i < N; ++i) {
        std::cin >> v[i]; // v[i] 는 i번 사람이 인출하는데 걸리는 시간.
    }

    // v[i]를 정렬시킨 후, 각 v[0] + (v[0] + v[1]) + (v[,,, 등 누적합을 다 차례대로 더한 것이 답.

//    삽입정렬 사용.
    // 3 1 4 3 2
    // 1 3 4 3 2
    // i = 2 / j = 0 pass
    // i = 3 / j = 2
    for (int i = 1; i < N; ++i) { // 정렬된 애들. 인덱스가 i
        int temp = v[i];
        for (int j = 0; j < i; ++j) { // 이번에 삽입 시킬 위치 찾아서 넣기.
            if (v[j] > v[i]) {
                for (int k = i; k > j; --k) { // shift right 할 때는 뒤에서 앞으로 순회.!! 값 유실되지 않게 하기 위해서.
                    v[k] = v[k - 1];
                }
                v[j] = temp;
                break;
            }
        }
    }

    s[0] = v[0];
    int answer = s[0];
    for (int i = 1; i < N; ++i) {
        s[i] = s[i-1] + v[i];
        answer += s[i];
    }
    std::cout << answer;
}