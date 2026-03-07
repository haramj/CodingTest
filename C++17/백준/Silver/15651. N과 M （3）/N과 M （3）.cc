#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

static int N, M;

static unordered_map<string, bool> visited;
static vector<int> v;

void dfs(int cur, int depth) {
    if (depth == M) {
        string s = "";
        for (int i = 0; i < M; ++i) {
            s += (char)(v[i] + 48);
            s += ' ';
        }
        if (visited.count(s) == 0) {
            visited[s] = true;
            cout << s << '\n';
        }
        return;
    }
    v[depth] = cur;

    for (int i = 1; i <= N; ++i) {
        dfs(i, depth + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    v = vector<int>(M);

    for (int i = 1; i <= N; ++i) {
        dfs(i, 0); // 1부터 시작, 깊이 0
    }


    return 0;
}