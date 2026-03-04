#include <string>
#include <vector>
#include <queue>

using namespace std;

static vector<int> visit;

void bfs(int computer, const vector<vector<int>> &computers) {
    queue<int> q;
    q.push(computer);
    visit[computer] = true;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < computers.size(); ++i) {
            if (i != cur && computers[cur][i] == 1 && !visit[i]) {
                visit[i] = true;
                q.push(i);
            }
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    
    visit = vector<int>(n, false);
    int answer = 0;
    
    for (int i = 0; i < n; ++i) {
        if (!visit[i]) {
            answer++;
            bfs(i, computers);
        }
    }

    return answer;
}