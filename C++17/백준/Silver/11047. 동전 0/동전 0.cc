//필요한 동전 개수의 최솟값
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    long long K;
    cin >> N >> K;
    priority_queue<int, vector<int>> q;
    for (int i = 1; i <= N; ++i) {
        int temp;
        cin >> temp;
        q.push(temp);
    }

    long long sum = 0;
    int answer = 0;
    while (!q.empty()) {
        int cur = q.top();
        q.pop();
        int count = 0;
        while (sum + cur * (count + 1) <= K) {
            count++;
        }
        sum += cur * count;
        answer += count;
        if (sum == K) break;
    }
    cout << answer;
}