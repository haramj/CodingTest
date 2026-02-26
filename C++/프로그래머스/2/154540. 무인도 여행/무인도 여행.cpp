// x는 바다 숫자는 무인도
// 지도의 각 칸에 적힌 숫자는 식량을 나타내는데, 상, 하, 좌, 우로 연결되는 칸에 적힌 숫자를 모두 합한 값은 해당 무인도에서 최대 며칠동안 머물 수 있는지를 나타냅니다.
// 각 섬에서 최대 며칠씩 머물 수 있는지. => 이건 BFS로 각 숫자 다 더하기 맞주?

#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <iostream>
#include <algorithm>

using namespace std;
typedef pair<int, int> pos;

static vector<vector<bool>> visit;
static int N, M;

static vector<int> dr = {-1, 1, 0, 0};
static vector<int> dc = {0, 0, -1, 1};

int bfs(int r, int c, const vector<string> &maps) {
    int answer = 0;
    queue<pos> q;
    q.push(pos(r, c));
    visit[r][c] = true;
    while (!q.empty()) {
        pos cur = q.front();
        answer += (int)(maps[cur.first][cur.second] - 48);
        q.pop();
        for (int i = 0; i < 4; ++i) {
            if (cur.first + dr[i] >= 0 && cur.first + dr[i] < N \
               && cur.second + dc[i] >= 0 && cur.second + dc[i] < M) {
                if (!visit[cur.first + dr[i]][cur.second + dc[i]] \
                    && maps[cur.first + dr[i]][cur.second + dc[i]] != 'X') {
                    q.push(pos(cur.first + dr[i], cur.second + dc[i]));
                    visit[cur.first + dr[i]][cur.second + dc[i]] = true;
                }
            }
        }
    }
    
    return answer;
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    
    N = maps.size();
    M = maps[0].size();
    
    visit = vector<vector<bool>>(N + 1, vector<bool>(M + 1, false));
    
    for (int i = 0; i < maps.size(); ++i) {
        for(int j = 0; j < maps[i].size(); ++j) {
            if (!visit[i][j] && maps[i][j] != 'X') { // 땅인데, 처음보는 땅이면 !
                int p = bfs(i, j, maps);
                answer.push_back(p);
            }
        }
    }
    
    if (answer.size() == 0) {
        answer.push_back(-1);
        return answer;
    }
    sort(answer.begin(), answer.end());
    return answer;
}