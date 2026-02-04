//첫째 줄에 최소 비교 횟수를 출력한다.
// 두 개 묶음 정렬된 -> A개 & B개 => A + B 번 비교.
//          -> 10 20 비교(30번비교) -> 30 40 비교(70번 비교) -> 총 100번 비교
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
    priority_queue<long long, vector<long long>, greater<long long>> q;

    for (int i = 1; i <= N; ++i) {
        int temp;
        cin >> temp;
        q.push(temp);
    }
    if (N == 1) {
        cout << 0;
        return 0;
    }

    // 새롭게 더해서 만들어진 숫자 묶음을 누적해서 비교하면 안 됨.
    // 새롭게 만들어진 숫자 묶음이 이미 정렬시켜 놓은 숫자 묶음 중 최소보다 클 수 있다!!! => 이 경우만 예외처리..? 아니면 다른 방법?

    long long answer = 0;
    while (q.size() > 1) {
        long long cp1 = q.top();
        q.pop();
        long long cp2 = q.top();
        q.pop();
        answer += cp1 + cp2;
        q.push(cp1 + cp2);
    }
    cout << answer;
}