#include <iostream>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;

typedef tuple<int, int, int, int> info; // row, col, 현재까지 이동한 회수, 벽 부신 여부 (1, 0);

static vector<int> dr = {-1, 1, 0, 0};
static vector<int> dc = {0, 0, -1, 1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    vector<vector<int>> board(N + 1, vector<int>(M + 1, 0));
    vector<vector<vector<bool>>> visited(2, vector<vector<bool>>(N + 1, vector<bool>(M + 1, false)));

    for (int i = 1; i <= N; ++i) {
        string temp;
        cin >> temp;
        for (int j = 1; j <= M; ++j) {
            board[i][j] = (int)(temp[j - 1] - 48);
        }
    }

    queue<info> q; // row, col, 현재까지 이동한 회수, 벽 부신 여부 (1, 0);
    q.push(info(1, 1, 1, 0));
    visited[0][1][1] = true; // 벽 안 부신 상태에서 1,1 true;

    while (!q.empty()) {
        info cur = q.front();
        q.pop();

        if (get<0>(cur) == N && get<1>(cur) == M) {
            cout << get<2>(cur);
            return 0;
        }

        for (int i = 0; i < 4; ++i) {
            if (get<0>(cur) + dr[i] >= 1 && get<0>(cur) + dr[i] <= N \
                && get<1>(cur) + dc[i] >= 1 && get<1>(cur) + dc[i] <= M
            ) {
                int nRow = get<0>(cur) + dr[i];
                int nCol = get<1>(cur) + dc[i];
                if (board[nRow][nCol] == 0) { // 벽 아닌 경우
                    if (get<3>(cur) == 1) { //벽 이미 부신 경우
                        if (!visited[1][nRow][nCol]){
                            visited[1][nRow][nCol] = true;
                            q.push(info(nRow, nCol, get<2>(cur) + 1, get<3>(cur)));
                        }
                    } else { // 안 부신 경우
                        if (!visited[0][nRow][nCol]){
                            visited[0][nRow][nCol] = true;
                            q.push(info(nRow, nCol, get<2>(cur) + 1, get<3>(cur)));
                        }
                    }
                } else { // 벽인경우
                    if (get<3>(cur) == 0) { // 아직 안 부심
                        if (!visited[1][nRow][nCol]) {
                            visited[1][nRow][nCol] = true;
                            q.push((info(nRow, nCol, get<2>(cur) + 1, 1)));
                        }
                    }
                }
            }
        }
    }
    cout << -1;

    return 0;
}