#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<int> D(N + 1);
    D[1] = 0;
    D[2] = 1;
    D[3] = 1;

    for (int i = 4; i <= N; ++i) {
        if (i % 6 == 0) {
            D[i] = min(D[i - 1], min(D[i / 3], D[i / 2])) + 1;
        }
        else if (i % 3 == 0) {
            D[i] = min(D[i - 1], D[i / 3]) + 1;
        } else if (i % 2 == 0) {
            D[i] = min(D[i - 1], D[i / 2]) + 1;
        } else {
            D[i] = D[i - 1] + 1;
        }
    }
    cout << D[N] << '\n';
}
