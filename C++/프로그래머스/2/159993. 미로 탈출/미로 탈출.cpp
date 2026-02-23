// 1x1 칸들로 이뤄진 직사각형 격자 형태의 미로에서 탈출. 각 칸은 통로 벽으로 구성
// 통로로만. 1. 레버 당기기 2. 미로밖으로 탈출
// 최소 거리 (다익스트라)
#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <climits>
#include <utility>
#include <tuple>

using namespace std;

typedef pair<int, int> pos; // first row second col
typedef tuple<int, int, int> info; // distance, row, col

vector<int> dr = {-1, 1, 0, 0};
vector<int> dc = {0, 0, -1, 1};

int solution(vector<string> maps) {
    pos startIndex, endIndex, lever;
    int answer = 0;
    bool isLever = false;
    
    for (int i = 0; i < maps.size(); ++i) {
        for (int j = 0; j < maps[i].size(); ++j) {
            if (maps[i][j] == 'S') {
                startIndex = pos(i, j);
            } else if (maps[i][j] == 'E') {
                endIndex = pos(i, j);
            } else if (maps[i][j] == 'L') {
                lever = pos(i, j);
            }
        }
    }
    
    // cout << startIndex.first << " " << startIndex.second << "\n";
    // cout << endIndex.first << " " << endIndex.second << "\n";
    // cout << lever.first << " " << lever.second << "\n";
    
    vector<vector<int>> D(maps.size(), vector<int>(maps[0].size(), INT_MAX));
    vector<vector<int>> visit(maps.size(), vector<int>(maps[0].size(), false));
    
    D[startIndex.first][startIndex.second] = 0;
    
    priority_queue<info, vector<info>, greater<info>> q; // 현재 최단경로, row, col
    
    q.push(info(0, startIndex.first, startIndex.second));
    
    while (!q.empty()) {
        info cur = q.top();
        q.pop();
        if (D[get<1>(cur)][get<2>(cur)] > get<0>(cur)){
            D[get<1>(cur)][get<2>(cur)] = get<0>(cur);
        }
        if (visit[get<1>(cur)][get<2>(cur)]) continue;
        visit[get<1>(cur)][get<2>(cur)] = true;
        for (int i = 0; i < 4; ++i) {
            if (get<1>(cur) + dr[i] >= 0 && get<1>(cur) + dr[i] < maps.size() \
                && get<2>(cur) + dc[i] >= 0 && get<2>(cur) + dc[i] < maps[0].size()) {
                int nRow = get<1>(cur) + dr[i];
                int nCol = get<2>(cur) + dc[i];
                if (maps[nRow][nCol] != 'X') {
                    q.push(info(get<0>(cur) + 1, nRow, nCol));   
                }
            }
        }
    }
    if (D[lever.first][lever.second] == INT_MAX) return -1;
    answer += D[lever.first][lever.second];
    D = vector<vector<int>>(maps.size(), vector<int>(maps[0].size(), INT_MAX));
    visit = vector<vector<int>>(maps.size(), vector<int>(maps[0].size(), false));
    
    D[lever.first][lever.second] = 0;
    
    q = priority_queue<info, vector<info>, greater<info>>(); // 현재 최단경로, row, col
    
    q.push(info(0, lever.first, lever.second));
    
    while (!q.empty()) {
        info cur = q.top();
        q.pop();
        if (D[get<1>(cur)][get<2>(cur)] > get<0>(cur)){
            D[get<1>(cur)][get<2>(cur)] = get<0>(cur);
        }
        if (visit[get<1>(cur)][get<2>(cur)]) continue;
        visit[get<1>(cur)][get<2>(cur)] = true;
        for (int i = 0; i < 4; ++i) {
            if (get<1>(cur) + dr[i] >= 0 && get<1>(cur) + dr[i] < maps.size() \
                && get<2>(cur) + dc[i] >= 0 && get<2>(cur) + dc[i] < maps[0].size()) {
                int nRow = get<1>(cur) + dr[i];
                int nCol = get<2>(cur) + dc[i];
                if (maps[nRow][nCol] != 'X') {
                    q.push(info(get<0>(cur) + 1, nRow, nCol));   
                }
            }
        }
    }
    if (D[endIndex.first][endIndex.second] == INT_MAX) return -1;
    answer += D[endIndex.first][endIndex.second];
    if (answer == INT_MAX) return -1;
    return answer;
}