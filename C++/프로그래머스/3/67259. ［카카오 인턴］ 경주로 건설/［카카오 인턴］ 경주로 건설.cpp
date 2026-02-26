#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <climits>
#include <iostream>

using namespace std;
typedef tuple<int, int, int, int> info; // row, col, 현재까지 최단경로, 이전 방향 0 1 2 3 상 하 좌 우

static vector<int> dr = {-1, 1, 0, 0};
static vector<int> dc = {0, 0, -1, 1};

struct compare {
    bool operator()(info i1, info i2) {
        return get<2>(i1) > get<2>(i2); // 최단경로 작은 순으로 우선순위 큐. // 작은 애 부터 visit 확정 짓기. 
    }
};

// 다익스트라..
int solution(vector<vector<int>> board) {
    int N = board.size();
    int M = board[0].size();
    
    vector<vector<bool>> visit(N, vector<bool>(M, false)); // 0 ~ N - 1, 0 ~ M - 1
    vector<vector<vector<int>>> D(N, vector<vector<int>>(M, vector<int>(4, INT_MAX))); 
    priority_queue<info, vector<info>, compare> q;
    
    // 평소에 계속 + 100 인데, 만일 q.push할 때 현재 방향이 다음 방향이랑 다르면 + 500 추가.
    q.push(info(0, 0, 0, -1)); // 이전방향 -1 이면 맨 처음.
    D[0][0][0] = 0;
    while (!q.empty()) {
        info cur = q.top();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            if (get<0>(cur) + dr[i] >= 0 && get<0>(cur) + dr[i] < N \
               && get<1>(cur) + dc[i] >= 0 && get<1>(cur) + dc[i] < M) {
                if (board[get<0>(cur) + dr[i]][get<1>(cur) + dc[i]] == 0) {
                    if (get<3>(cur) < 0) { // 초기 그냥 넘어감.
                        q.push(info(get<0>(cur) + dr[i], get<1>(cur) + dc[i], get<2>(cur) + 100, i));
                        D[get<0>(cur) + dr[i]][get<1>(cur) + dc[i]][i] = get<2>(cur) + 100;
                    } else {
                        if (i != get<3>(cur)){ // 방향 바뀌는 경우
                            if (get<2>(cur) + 600 < D[get<0>(cur) + dr[i]][get<1>(cur) + dc[i]][i]) {
                                q.push(info(get<0>(cur) + dr[i], get<1>(cur) + dc[i], get<2>(cur) + 600, i));
                                D[get<0>(cur) + dr[i]][get<1>(cur) + dc[i]][i] = get<2>(cur) + 600;
                            }
                                
                        } else { // 방향 안 바뀌는 경우
                            if (get<2>(cur) + 100 < D[get<0>(cur) + dr[i]][get<1>(cur) + dc[i]][i]) {
                                q.push(info(get<0>(cur) + dr[i], get<1>(cur) + dc[i], get<2>(cur) + 100, i)); 
                                D[get<0>(cur) + dr[i]][get<1>(cur) + dc[i]][i] = get<2>(cur) + 100;
                            }
                                
                        }
                    }
                }
            }
        }
    }
    int answer = D[N - 1][M - 1][0];
    for (int i = 1; i < 4; ++i) {
        if (D[N - 1][M - 1][i] < answer) answer = D[N - 1][M - 1][i];
    }
    
    return answer;
}