// 수열의 특수한 합의 값이 최대가 되도록...
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    // 우선순위큐..-> 양수 큐(내림), 음수 큐(오름), 0 개수 따로 담기.
    priority_queue<int> posQ;
    priority_queue<int, vector<int>, greater<int>> negQ;
    int zeroCount = 0;

    for (int i = 1; i <= N; ++i) {
        int input;
        cin >> input;
        if (input > 0) {
            posQ.push(input);
        } else if (input < 0) {
            negQ.push(input);
        } else if (input == 0) {
            zeroCount++;
        }
    }
    long long answer = 0;
    while (posQ.size() > 1) {
        int n1 = posQ.top();
        posQ.pop();
        int n2 = posQ.top();
        posQ.pop();
        if (n1 == 1 || n2 == 1) answer += n1 + n2;
        else answer += n1 * n2;
    }

    while (negQ.size() > 1) {
        int n1 = negQ.top();
        negQ.pop();
        int n2 = negQ.top();
        negQ.pop();
        answer += n1 * n2;
    }

    if (!zeroCount) { // 쩔 수 없이 그냥 더해야 됨.
        if (!negQ.empty()) {
            answer += negQ.top();
        }
    }

    if (!posQ.empty()) {
        answer += posQ.top();
    }

    cout << answer;
}