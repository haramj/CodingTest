#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> info; // 칸, 현재까지 몇번 이동?

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M; // 사디리 수, 뱀 수

    cin >> N >> M;

    unordered_map<int, int> po;
    for (int i = 0; i < N + M; ++i) {
        int s, e;
        cin >> s >> e;
        po[s] = e;
    }

    vector<bool> visited(101, false);

    queue<info> q; // 칸, 현재까지 몇번 이동?

    q.push(info(1, 0));
    visited[1] = true;
    if (po.count(1) && !visited[po[1]]) {
        q.push(info(po[1], 0));
        visited[po[1]] = true;
    }
    // answer
    int answer = INT_MAX;

    while (!q.empty()) {
        info cur = q.front();
        q.pop();
        if (cur.first == 100) {
            if (answer > cur.second) answer = cur.second;
            continue;
        }
        int next;
        for (int i = 1; i <= 6; ++i) {
            next = cur.first + i;

            if (next > 100) continue;

            int finalNext = next;
            while (po.count(finalNext)) {
                finalNext = po[finalNext]; // 사다리 끝에 사다리가 있어도 끝까지 추적
            }

            // [핵심] 최종 목적지가 방문한 적 없는 곳일 때만 큐에 넣는다!
            if (!visited[finalNext]) {
                visited[finalNext] = true;
                q.push({finalNext, cur.second + 1});
            }
        }
    }
    cout << answer;
    return 0;
}