#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <tuple>

using namespace std;

typedef pair<int, int> pos;
typedef tuple<int, int, int> info; // row, col, 현재까지 이동 횟수

static vector<int> dr = {-2, -2, -1, -1, +1, +1, +2, +2};
static vector<int> dc = {-1, +1, -2, +2, -2, +2, +1, -1};

void func() {
    int N;
    pos s, e;
    cin >> N;
    cin >> s.first >> s.second;
    cin >> e.first >> e.second;

    vector<vector<bool>> visited(N, vector<bool>(N, false));
    queue<info> q;

    q.push(info(s.first, s.second, 0));
    visited[s.first][s.second] = true;
    while (!q.empty()) {
        info cur = q.front();
        q.pop();

        if (get<0>(cur) == e.first && get<1>(cur) == e.second) {
            cout << get<2>(cur) << '\n';
            return;
        }

        for (int i = 0; i < 8; ++i) {
            int nRow = get<0>(cur) + dr[i];
            int nCol = get<1>(cur) + dc[i];
            if (nRow >= 0 && nRow <= N - 1 \
                && nCol >= 0 && nCol <= N - 1 \
                && !visited[nRow][nCol]
            ) {
                q.push(info(nRow, nCol, get<2>(cur) + 1));
                visited[nRow][nCol] = true;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    for (int i = 0; i < T; ++i) {
        func();
    }
}