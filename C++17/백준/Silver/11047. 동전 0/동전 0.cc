//필요한 동전 개수의 최솟값
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    long long K;
    cin >> N >> K;
    stack<int> s;
    
    for (int i = 1; i <= N; ++i) {
        int temp;
        cin >> temp;
        s.push(temp);
    }

    int answer = 0;
    while (!s.empty()) {
        int cur = s.top();
        s.pop();
        if (cur <= K) {
            answer += (int)K / cur;
            K %= cur;
        }
        if (K == 0) break;
    }
    cout << answer;
}