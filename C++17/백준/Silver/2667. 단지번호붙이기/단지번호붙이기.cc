#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<int, int> pos; // row , col

static vector<vector<int>> board;
static vector<vector<bool>> visited;
static vector<int> v; // 단지 내 집들 수

static vector<int> dr = {-1, 1, 0, 0};
static vector<int> dc = {0, 0, -1, 1};

static int N;

void bfs(int row, int col) {
    queue<pos> q;

    int cnt = 1;
    q.push(pos(row, col));
    visited[row][col] = true;

    while (!q.empty()) {
        pos cur = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nRow = cur.first + dr[i];
            int nCol = cur.second + dc[i];
            if (nRow >= 0 && nRow <= N - 1 \
                && nCol >= 0 && nCol <= N - 1 \
                && !visited[nRow][nCol] && board[nRow][nCol] == 1
            ) {
                cnt++;
                q.push(pos(nRow, nCol));
                visited[nRow][nCol] = true;
            }
        }
    }

    v.push_back(cnt);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    board = vector<vector<int>>(N, vector<int>(N, 0));
    visited = vector<vector<bool>>(N, vector<bool>(N, false));

    for (int i = 0; i < N; ++i) {
        string temp;
        cin >> temp;
        for (int j = 0; j < N; ++j) {
            board[i][j] = (int)(temp[j] - 48);
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (board[i][j] == 1 && !visited[i][j]) {
                bfs(i, j);
            }
        }
    }

    cout << v.size() << '\n';
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << '\n';
    }
    return 0;
}