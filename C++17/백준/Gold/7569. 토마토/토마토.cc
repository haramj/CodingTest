#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

typedef tuple<int, int, int, int> info; // row, col, height, 현재까지 개수.

static vector<int> dr = {-1, 1, 0, 0, 0, 0};
static vector<int> dc = {0, 0, -1, 1, 0, 0};
static vector<int> dh = {0, 0, 0, 0, 1, -1};

static int N, M, H, cnt = 0, notIc = 0;
static vector<vector<vector<int>>> board;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M >> N >> H;

    board = vector<vector<vector<int>>>(N, vector<vector<int>>(M, vector<int>(H, 0)));
    notIc = 0;
    queue<info> q;

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < M; ++k) {
                int input;
                cin >> input;
                board[j][k][i] = input;
                if (input == 0) notIc++;
                else if (input == 1) q.push(info(j, k, i, 1)); // 익은 애들 모두 queue 에 넣기.
            }
        }
    }

    if (notIc == 0) {
        cout << 0;
        return 0;
    }

    while (!q.empty()) {
        info cur = q.front();
        q.pop();

        for (int i = 0; i < 6; ++i) {
            if (get<0>(cur) + dr[i] >= 0 && get<0>(cur) + dr[i] < N \
                && get<1>(cur) + dc[i] >= 0 && get<1>(cur) + dc[i] < M \
                && get<2>(cur) + dh[i] >= 0 && get<2>(cur) + dh[i] < H \
                && board[get<0>(cur) + dr[i]][get<1>(cur) + dc[i]][get<2>(cur) + dh[i]] == 0
            ) {
                board[get<0>(cur) + dr[i]][get<1>(cur) + dc[i]][get<2>(cur) + dh[i]] = 1;
                q.push(info(get<0>(cur) + dr[i], get<1>(cur) + dc[i], get<2>(cur) + dh[i], get<3>(cur) + 1));
                cnt++;
            }
        }

        if (cnt == notIc) {
            cout << get<3>(cur);
            return 0;
        }
    }

    cout << -1;

    return 0;
}