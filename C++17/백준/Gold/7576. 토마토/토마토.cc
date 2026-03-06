#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <tuple>

using namespace std;

typedef pair<int, int> pos;
typedef tuple<int, int, int> info; // row, col, 현재까지 개수.

static vector<int> dr = {-1, 1, 0, 0};
static vector<int> dc = {0, 0, -1, 1};

static int N, M, cnt = 0, notIc = 0;
static vector<vector<int>> board;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M >> N;

    board = vector<vector<int>>(N, vector<int>(M, 0));
    notIc = 0;
    queue<info> q;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            int input;
            cin >> input;
            board[i][j] = input;
            if (input == 0) notIc++;
            else if (input == 1) q.push(info(i, j, 1)); // 익은 애들 모두 queue 에 넣기.
        }
    }

    if (notIc == 0) {
        cout << 0;
        return 0;
    }

    while (!q.empty()) {
        info cur = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            if (get<0>(cur) + dr[i] >= 0 && get<0>(cur) + dr[i] < N \
                && get<1>(cur) + dc[i] >= 0 && get<1>(cur) + dc[i] < M \
                && board[get<0>(cur) + dr[i]][get<1>(cur) + dc[i]] == 0
            ) {
                board[get<0>(cur) + dr[i]][get<1>(cur) + dc[i]] = 1;
                q.push(info(get<0>(cur) + dr[i], get<1>(cur) + dc[i], get<2>(cur) + 1));
                cnt++;
            }
        }
        if (cnt == notIc) {
            cout << get<2>(cur);
            return 0;
        }
    }

    cout << -1;

    return 0;
}