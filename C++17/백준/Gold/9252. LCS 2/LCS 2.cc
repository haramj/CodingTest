 #include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s1, s2;
    cin >> s1 >> s2;

    vector<vector<int>> D(s1.size() + 1, vector<int>(s2.size() + 1, 0));
    // D[i][j] s1 0~i-1까지 s2 0~j-1까지 최장공통부분수열 길이.

    for (int i = 1; i <= (int)s1.size(); ++i) {
        for (int j = 1; j <= (int)s2.size(); ++j) {
            if (s1[i - 1] == s2[j - 1]) {
                D[i][j] = D[i - 1][j - 1] + 1;
            } else {
                D[i][j] = max(D[i - 1][j], D[i][j - 1]);
            }
        }
    }
//
//    for (int i = 1; i <= 6; ++i) {
//        for (int j = 1; j <= 6; ++j) {
//            cout << D[i][j] << " ";
//        } cout << '\n';
//    }

    int size = D[s1.size()][s2.size()];
    cout << size << '\n';
    if (size) {
        stack<char> s;
        int curI = (int)s1.size();
        int curJ = (int)s2.size();
        while (curI > 0 && curJ > 0) {
            if (D[curI][curJ] == D[curI][curJ - 1]) {
                curJ--;
            } else if (D[curI][curJ] == D[curI - 1][curJ]) {
                curI--;
            } else {
                s.push(s1[curI - 1]);
                curI--;
                curJ--;
            }
        }

        while (!s.empty()) {
            cout << s.top();
            s.pop();
        }
    }
}