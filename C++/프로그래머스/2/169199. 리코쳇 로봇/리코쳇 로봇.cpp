// 시작 위치에서 출발한 뒤 목표 위치에 정확하게 멈추기 위해 최소 몇 번의 이동
// 상, 하, 좌, 우 중 한 방향으로 게임판 위의 장애물이나 게임판 가장자리까지 부딪힐 때까지 미끄러져 움직이는 것


#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <tuple>
#include <utility>

using namespace std;

typedef tuple<int, int, int> info; // 0 row 1 col 2 거리
typedef pair<int, int> pos;

vector<int> dr = {-1, 1, 0, 0};
vector<int> dc = {0, 0, -1, 1};

static vector<vector<bool>> visit;
static int N, M; // 세로, 가로

int solution(vector<string> board) {
    N = board.size();
    M = board[0].size();
    visit = vector<vector<bool>>(N + 1, vector<bool>(M + 1, false));
    pos rPos, gPos;
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0 ; j < board[i].size(); ++j) {
            if (board[i][j] == 'R') {
                rPos = pos(i, j);
            } else if (board[i][j] == 'G') {
                gPos = pos(i, j);
            }
        }
    }
    
    queue<info> q;
    q.push(info(rPos.first, rPos.second, 0));
    while (!q.empty()) {
        info cur = q.front();
        q.pop();
        if (get<0>(cur) == gPos.first && get<1>(cur) == gPos.second) {
            return get<2>(cur);
        }
        bool isTrue = false;
        for (int i = 0; i < 4; ++i) {
            if (get<0>(cur) + dr[i] >= 0 && get<0>(cur) + dr[i] < N \
               && get<1>(cur) + dc[i] >= 0 && get<1>(cur) + dc[i] < M) {
                // out of bounds 방지 -> 접근 가능한 방향임.
                int nRow = get<0>(cur);
                int nCol = get<1>(cur); // x0
                while (nRow + dr[i] >= 0 && nRow + dr[i] < N \
               && nCol + dc[i] >= 0 && nCol + dc[i] < M) {
                    nRow += dr[i];
                    nCol += dc[i];
                    if (board[nRow][nCol] == 'D') {
                        nRow -= dr[i];
                        nCol -= dc[i];
                        break;
                    }
                }
                if (visit[nRow][nCol] == false) {
                    isTrue = true;
                    visit[nRow][nCol] = true;
                    q.push(info(nRow, nCol, get<2>(cur) + 1));
                }
                
            }
        }
    }
    
    return -1;
}