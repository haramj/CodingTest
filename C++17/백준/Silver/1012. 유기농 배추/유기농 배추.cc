#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

static int N, M, K; // 가로, 세로, 개수
static vector<vector<int>> board;
static vector<vector<bool>> visited;

typedef pair<int, int> pos;

static vector<int> dr = {-1, 1, 0, 0};
static vector<int> dc = {0, 0, 1, -1};

void bfs(int r, int c) {
    queue<pos> q;
    q.push(pos(r, c));
    visited[r][c] = true;
    while (!q.empty()) {
        pos cur = q.front();
        int row = cur.first;
        int col = cur.second;
        q.pop();
        for (int i = 0; i < 4; ++i) {
            if (row + dr[i] >= 0 && row + dr[i] < M \
            && col + dc[i] >= 0 && col + dc[i] < N) {
                int nRow = row + dr[i];
                int nCol = col + dc[i];
                if (!visited[nRow][nCol] && board[nRow][nCol] == 1) {
                    q.push(pos(nRow, nCol));
                    visited[nRow][nCol] = true;
                }
            }
        }
    }
}

void sol() {
    cin >> N >> M >> K; // 가로 세로 위치
    board = vector<vector<int>>(M + 1, vector<int>(N + 1, 0));
    visited = vector<vector<bool>>(M + 1, vector<bool>(N + 1, false));

    for (int i = 0; i < K; ++i) {
        int x, y;
        cin >> x >> y;
        board[y][x] = 1;
    }

    int cnt = 0;

    for (int i = 0; i < M; ++i) { // 세로
        for (int j = 0; j < N; ++j) { // 가로
            if (!visited[i][j] && board[i][j] == 1) {
                cnt++;
                bfs(i, j);
            }
        }
    }

    cout << cnt << '\n';
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