#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    int kMax, nMax;
    vector<int> ks;
    vector<int> ns;

    for (int i = 1; i <= T; ++i) {
        int k, n; // k층 n호
        cin >> k >> n;
        if (i == 1) {
            kMax = k;
            nMax = n;
        }
        else {
            if (k > kMax) kMax = k;
            if (n > nMax) nMax = n;
        }
        ks.push_back(k);
        ns.push_back(n);
    }
    vector<vector<int>> D(kMax + 1, vector<int>(nMax + 1, 0));
    for (int i = 1; i <= nMax; ++i) {
        D[0][i] = i;
    }
    for (int i = 1; i <= kMax; ++i) { // 1 ~ 2
        int sum = 0;
        for (int j = 1; j <= nMax; ++j) { // 1 ~ 3
            sum += D[i - 1][j];
            D[i][j] = sum;
//            cout << D[i][j] << '\n';
        }
    }
    for (int i = 0; i < ks.size(); ++i) {
        cout << D[ks[i]][ns[i]] << '\n';
    }
}