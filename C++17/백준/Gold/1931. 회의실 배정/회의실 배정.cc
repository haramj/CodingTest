// 각 시간들 long long 무조건 써야 할 듯
// 시작시간 -> (끝나는 시간 - 시작 시간) 으로 정렬(우선순위 큐)
#include <iostream>
#include <queue>
#include <vector>
#include <tuple>

using namespace std;

typedef pair<long long, long long> conf; // first 시작시간 second 끝나는시간

struct compare {
    bool operator() (conf c1, conf c2) {
        if (c1.first == c2.first) { // 시작 시간이 같으면 회의 시간 오름차순으로 정렬.
            return (c1.second - c1.first) > (c2.second - c2.first);
        }
        return c1.first > c2.first;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    priority_queue<conf, vector<conf>, compare> q;
    for (int i = 1; i <= N; ++i) {
        conf input;
        cin >> input.first >> input.second;
        q.push(input);
    }

    // 일단 현재로 하고 answer++
    // 그런데 다음꺼가 더 빨리 끝나면 그거로 바꾸기.

    conf curConf = q.top(); // 진행중인 회의
    bool notDone = true; // 진행중인 게 없으면 false
    int answer = 1;
    q.pop();
    while (!q.empty()) {
        conf cur = q.top();
        q.pop();
        if (cur.first >= curConf.second) { // 진행중이던 회의가 끝나는 시간 <= 지금보는 회의가 시작하는 시간.
            notDone = false;
        }
        if (!notDone) { // 진행중인 회의 없으면.
            curConf = cur;
            notDone = true;
            answer++;
            continue;
        }
        if (cur.second < curConf.second) {
            curConf = cur;
        }
    }
    cout << answer;
}