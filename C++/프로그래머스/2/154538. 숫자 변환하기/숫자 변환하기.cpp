#include <string>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int solution(int x, int y, int n) {
    // dp로.
    // dp[i] = x가 i가 되는 최소 연산 횟수.
    // i >= x;
    vector<int> d(y + 1, INT_MAX);
    d[x] = 0;
    for (int i = x; i <= y; ++i) {
        // cout << i << '\n';
        int a = INT_MAX, b = INT_MAX, c = INT_MAX;
        if (i / 3 >= x && i % 3 == 0 && d[i / 3] != INT_MAX) {
            a = d[i / 3] + 1;
        } if (i / 2 >= x && i % 2 == 0 && d[i / 2] != INT_MAX) {
            b = d[i / 2] + 1;
        } if (i - n >= x && d[i - n] != INT_MAX) {
            c = d[i - n] + 1;
        }
        d[i] = min({a, b, c, d[i]});
        // cout << d[i] << '\n';
    }
    if (d[y] == INT_MAX) return -1;
    return d[y];
}