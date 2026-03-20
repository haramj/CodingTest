// 나머지 연산으로 row : 0 ~ N - 1 / col : 0 ~ M - 1
// 로 갈 수 있게 !!
// 이거 말고는 다른 것들이랑 비슷한 듯.

// 이슈  -> 음수 나머지 연산 -> -1 % 5 -> -1 나옴 -> -1 % 5 -> 4가 나와야 함.
#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

typedef pair<int, int> pos; // row , col

static int N, M, answer = 0;

static vector<int> dr = {-1, 1, 0, 0};
static vector<int> dc = {0, 0, -1, 1};

static vector<vector<bool>> visited;
static vector<vector<int>> board;

void BFS(int r, int c) {
    queue<pos> q;
    q.push(pos(r, c));
    visited[r][c] = true;

    while (!q.empty()) {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nRow = (row + dr[i] + N) % N; // 이부분..!
            int nCol = (col + dc[i] + M) % M;
            if (board[nRow][nCol] == 0 && !visited[nRow][nCol]) {
                q.push(pos(nRow, nCol));
                visited[nRow][nCol] = true;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    visited = vector<vector<bool>>(N, vector<bool>(M, false));
    board = vector<vector<int>>(N, vector<int>(M, 0));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) { // 0이면이동
            if (board[i][j] == 0 && !visited[i][j]) {
                answer++;
                BFS(i, j);
            }
        }
    }

    cout << answer;
    return 0;
}