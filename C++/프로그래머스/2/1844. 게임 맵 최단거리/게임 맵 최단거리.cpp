#include <vector>
#include <queue>
#include <iostream>
#include <tuple>

using namespace std;

typedef tuple<int, int, int> info; // 0 row 1 col 2 distance

static vector<int> dr = {-1, 1, 0, 0};
static vector<int> dc = {0, 0, -1, 1};

int solution(vector<vector<int> > maps)
{ // push 할 때 주요값 업데이트.
    queue<info> q;
    vector<vector<bool>> visit(maps.size(), vector<bool>(maps[0].size(), false));
    
    int answer = 0;
    q.push(info(0, 0, 1));
    visit[0][0] = true;
    while (!q.empty()) {
        bool isTrue = false;
        info cur = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            if (dr[i] + get<0>(cur) >= 0 && dr[i] + get<0>(cur) < maps.size() \
               && dc[i] + get<1>(cur) >= 0 && dc[i] + get<1>(cur) < maps[0].size()) {
                int nr = dr[i] + get<0>(cur);
                int nc = dc[i] + get<1>(cur);
                if (!visit[nr][nc] && maps[nr][nc] == 1) {
                    visit[nr][nc] = true;
                    q.push(info(nr, nc, get<2>(cur) + 1));
                    if (nr == maps.size() - 1 && nc == maps[0].size() - 1) isTrue = true;
                }
            }
        }
        if (isTrue) return get<2>(cur) + 1;
    }
    return -1;
}