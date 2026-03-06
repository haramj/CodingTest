#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <utility>

using namespace std;

typedef pair<int, int> pos; // r, c
typedef tuple<int, int, int> info; // r, c, count

static vector<int> dr = {-2, -2, -1, -1, 1, 1, 2, 2};
static vector<int> dc = {-1, 1, -2, 2, -2, 2, -1, 1};

void sol() {
    int I;
    cin >> I;
    pos firstPos;
    cin >> firstPos.first >> firstPos.second;
    pos targetPos;
    cin >> targetPos.first >> targetPos.second;

    vector<vector<int>> board(I, vector<int>(I, 0));
    board[targetPos.first][targetPos.second] = 2; // 2는 목표 1은 이미 방문한 곳 나머지 0

    queue<info> q;

    if (firstPos.first == targetPos.first && firstPos.second == targetPos.second) {
        cout << 0 << '\n';
        return;
    }

    board[firstPos.first][firstPos.second] = 1;
    q.push(info(firstPos.first, firstPos.second, 0));

    while (!q.empty()) {
        info cur = q.front();
        q.pop();

        for (int i = 0; i < 8; ++i) {
            if (get<0>(cur) + dr[i] >= 0 && get<0>(cur) + dr[i] < I \
            && get<1>(cur) + dc[i] >= 0 && get<1>(cur) + dc[i] < I) {
                int nRow = get<0>(cur) + dr[i];
                int nCol = get<1>(cur) + dc[i];
                if (board[nRow][nCol] == 0) {
                    board[nRow][nCol] = 1;
                    q.push(info(nRow, nCol, get<2>(cur) + 1));
                } else if (board[nRow][nCol] == 2) {
                    cout << get<2>(cur) + 1 << '\n';
                    return;
                }
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
        sol();
    }

    return 0;
}