#include <iostream>
#include <vector>

using namespace std;

static int N, M;
static vector<int> v;

void dfs(int cur, int depth) {
    if (depth == M) {
        // 정렬 했을 때 이미 한 거면 안 되게
        for (int i = 0; i < M; ++i) {
            cout << v[i] << " ";
        } cout << '\n';
        return;
    }

    for (int i = cur; i <= N; ++i) {
        v.push_back(i);

        dfs(i, depth + 1);

        v.pop_back();
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