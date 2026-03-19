#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

static vector<vector<int>> board;
static vector<vector<bool>> visited;
static int N, M, answer = 0;

static vector<int> dr = {-1, 1, 0, 0};
static vector<int> dc = {0, 0, -1, 1};

typedef pair<int, int> pos; // r, c

void BFS(int r, int c) {
    int cnt = 0;
    queue<pos> q;
    visited[r][c] = true;
    q.push(pos(r, c));
    cnt++;

    while (!q.empty()) {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i) {
            if (row + dr[i] >= 0 && row + dr[i] <= N - 1 \
            && col + dc[i] >= 0 && col + dc[i] <= M - 1 \
            && !visited[row + dr[i]][col + dc[i]] && board[row + dr[i]][col + dc[i]] == 1) {
                visited[row + dr[i]][col + dc[i]] = true;
                q.push(pos(row + dr[i], col + dc[i]));
                cnt++;
            }
        }
    }

    if (answer < cnt) answer = cnt;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    int pic = 0;
    board = vector<vector<int>>(N, vector<int>(M, 0));
    visited = vector<vector<bool>>(N, vector<bool>(M, false));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (board[i][j] == 1 && !visited[i][j]) {
                pic++;
                BFS(i, j);
            }
        }
    }
    cout << pic << '\n';
    cout << answer;
    return 0;
}