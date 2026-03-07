#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

static int N, M;

static vector<int> v;

void dfs(int cur, int depth) {
    if (depth == M) { // 종료조건
        for (int i = 0; i < M; ++i) {
            cout << v[i] << " ";
        } cout << '\n';
        return;
    }

    for (int i = cur; i <= N; ++i) { // 아무 숫자나 다 붙여도 됨.
        v.push_back(i); // 체크인

        dfs(i + 1, depth + 1); // 전진

        v.pop_back(); // 체크아웃
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    dfs(1, 0);

    return 0;
}