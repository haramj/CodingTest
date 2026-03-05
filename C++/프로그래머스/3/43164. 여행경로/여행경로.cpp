#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

typedef pair<string, string> ticket;

static vector<string> path;
static map<ticket, int> visit; // 남은 티켓
static int N;
static bool found = false;

void dfs(int depth, vector<string> &path, const vector<vector<string>> &tickets) {
    string cur =  path[path.size() - 1];
    if (depth == N) {
        found = true;
        return;
    }
    
    // 체크인 (visit true)
    string next;
    for (int i = 0; i < tickets.size(); ++i) {
        if (visit[ticket(cur, tickets[i][1])] >= 1 \
            && tickets[i][0] == cur) { // tickets[i][0] 티켓 중에 알파벳 순서 먼저인 거.
            next = tickets[i][1];
            visit[ticket(cur, next)]--;
            path.push_back(next);
            // dfs 깊게 가기. path 갱신하면서
            dfs(depth + 1, path, tickets);
            
            if (found) return; // 찾은 경우 백트레킹 함
            
            // 체크아웃 (백트레킹) (visit false)
            visit[ticket(cur, next)]++;
            path.pop_back();
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    N = tickets.size();
    
    for (int i = 0; i < tickets.size(); ++i) {
        visit[ticket(tickets[i][0], tickets[i][1])]++;
    }
    
    sort(tickets.begin(), tickets.end());
    
    // ICN -> 시작하는 거
    vector<string> answer = {"ICN"};
    dfs(0, answer, tickets);
    
    return answer;
}