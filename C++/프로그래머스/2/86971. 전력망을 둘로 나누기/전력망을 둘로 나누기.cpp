#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

static vector<bool> visit;
static vector<vector<int>> adj;
typedef pair<int, int> info;

int bfs(const vector<vector<int>> &wire, int n, int k) {
    // 하나 쪽만 세고 n - cur, cur 의 차이를 리턴.
    // wire[k][0] wire[k][1] 이 서로 연결되는 간선을 발견하면 q.push 안 하기.
    queue<info> q; // f 개수, s 현재 노드
    vector<bool> visit(n + 1, false);
    q.push(info(1, 1));
    int count = 0;
    while (!q.empty()) {
        info cur = q.front();
        q.pop();
        if (visit[cur.second]) continue;
        count++;
        visit[cur.second] = true;
        for (int i = 0; i < adj[cur.second].size(); ++i) {
            //cur.second 지금 노드번호
            //adj[cur.second][i] 다음 갈 노드번호.
            if (cur.second == wire[k][0] && adj[cur.second][i] == wire[k][1] || \
               cur.second == wire[k][1] && adj[cur.second][i] == wire[k][0]) {
                continue;
            }
            
            if (!visit[adj[cur.second][i]]) {
                q.push(info(cur.first + 1, adj[cur.second][i]));
            }
        }
    }
    
    if (n - count - count > 0) return n - count - count;
    else return (-1) * (n - count - count);
}

int solution(int n, vector<vector<int>> wires) {
    // wires 정렬
    sort(wires.begin(), wires.end());
    adj = vector<vector<int>>(n + 1);
    for (int i = 0; i < wires.size(); ++i) {
        adj[wires[i][0]].push_back(wires[i][1]);
        adj[wires[i][1]].push_back(wires[i][0]);
    }
    int answer = n;
    int cur;
    for (int i = 0; i < wires.size(); ++i) {
        // wires[i] 지금 탐색에서 무시할 간선.
        cur = bfs(wires, n, i);
        if (cur < answer) answer = cur;
    }
    return answer;
}