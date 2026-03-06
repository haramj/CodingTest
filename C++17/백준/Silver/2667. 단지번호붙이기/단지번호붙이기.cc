#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;

static vector<int> answer; // 단지 배열
static vector<vector<int>> board; // 보드
static vector<vector<bool>> visited;
static int cnt = 0;
static int N; // 지도 크기

static vector<int> dr = {-1, 1, 0, 0};
static vector<int> dc = {0, 0, -1, 1};

typedef pair<int, int> pos; // r, c

void BFS(int r, int c) {
    // cnt 가 개수. !!
    int size = 0;
    queue<pos> q;
    q.push(pos(r, c));
    visited[r][c] = true;
    size++;

    while (!q.empty()) {
        pos cur = q.front();
        int row = cur.first;
        int col = cur.second;
        q.pop();

        for (int i = 0; i < 4; ++i) {
            if (row + dr[i] >= 0 && row + dr[i] < N \
                && col + dc[i] >= 0 && col + dc[i] < N \
                && !visited[row + dr[i]][col + dc[i]] \
                && board[row + dr[i]][col + dc[i]] != 0) {
                q.push(pos(row + dr[i], col + dc[i]));
                visited[row + dr[i]][col + dc[i]] = true;
                size++;
            }
        }
    }

    answer.push_back(size);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    board = vector<vector<int>>(N, vector<int>(N, 0));
    visited = vector<vector<bool>>(N, vector<bool>(N, false));

    for (int i = 0; i < N; ++i) {
        string row;
        cin >> row;
        for (int j = 0; j < N; ++j) {
            board[i][j] = (int)(row[j] - 48);
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (!visited[i][j] && board[i][j] != 0) {
                cnt++;
                BFS(i, j);
            }
        }
    }

    sort(answer.begin(), answer.end());

    cout << cnt << '\n';
    for (int i = 0; i < answer.size(); ++i) {
        cout << answer[i] << '\n';
    }

    return 0;
}