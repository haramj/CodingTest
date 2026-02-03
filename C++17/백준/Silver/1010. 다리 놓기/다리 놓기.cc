//  서쪽 i 동쪽 j 일 때 개수 D[i][j] = D[i - 1][  i - 1 ~~~ j - 1  ] 범위 합.
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    // left right
    vector<int> left;
    vector<int> right;
    int maxLeft;
    int maxRight;

    for (int i = 1; i <= N; ++i) {
        int leftValue, rightValue;
        cin >> leftValue >> rightValue;
        if (i == 1) {
            maxLeft = leftValue;
            maxRight = rightValue;
        } else {
            if (maxLeft < leftValue) maxLeft = leftValue;
            if (maxRight < rightValue) maxRight = rightValue;
        }
        left.push_back(leftValue);
        right.push_back(rightValue);
    }

    //  서쪽 i 동쪽 j 일 때 개수 D[i][j] = D[i - 1][  i - 1 ~~~ j - 1  ] 범위 합.
    vector<vector<int>> D(maxLeft + 1, vector<int>(maxRight + 1, 0));
    for (int i = 0; i <= maxRight; ++i) {
        D[0][i] = 0;
        D[1][i] = i;
        if (i <= maxLeft) D[i][i] = 1;
    }

    for (int i = 2; i <= maxLeft; ++i) {
        for (int j = i; j <= maxRight; ++j) {
            int sum = 0;
            for (int k = i - 1; k <= j - 1; ++k) {
                sum += D[i - 1][k];
            }
            D[i][j] = sum;
        }
    }

    for (int i = 0; i < left.size(); ++i) {
        cout << D[left[i]][right[i]] << '\n';
    }
}