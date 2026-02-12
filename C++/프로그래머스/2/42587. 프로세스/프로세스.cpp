#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

// 특정 프로세스가 몇 번째로 실행되는지.
// 실행 대기 큐에서 대기중인 프로세스를 꺼냄.
// 큐에 대기 중인 애 중에 우선순위가 더 높은 애가 있으면 걔로 한다.
// 우선 순위 높은 애 없으면 걔 실행.
int solution(vector<int> priorities, int location) {
    // first 우선순위 second 인덱스
    queue<pair<int, int>> q; // first priority, second index;
    priority_queue<int> priQ;
    for (int i = 0; i < priorities.size(); ++i) {
        q.push(pair<int, int>(priorities[i], i));
        priQ.push(priorities[i]);
    }
    int answer = 0;
    while (!q.empty()) {
        pair<int, int> cur = q.front();
        int curMaxPri = priQ.top();
        q.pop();
        if (curMaxPri != cur.first) {
            q.push(cur);
            continue;
        }
        priQ.pop();
        answer++;
        if (cur.second == location) return answer;
    }
    
}