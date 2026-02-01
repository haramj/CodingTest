#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>

using namespace std;

static int N, M, k;
static vector<long long> v;
static vector<long long> tree;

void getMin(int s, int e, const vector<long long> &t) {
    int startIndex = s + (int)pow(2, k) - 1;
    int endIndex = e + (int)pow(2, k) - 1;
    long long minValue = LONG_LONG_MAX;
    while (startIndex <= endIndex) {
        if (startIndex % 2 == 1) {
            if (t[startIndex] < minValue) minValue = t[startIndex];
        }
        if (endIndex % 2 == 0) {
            if (t[endIndex] < minValue) minValue = t[endIndex];
        }
        startIndex = (startIndex + 1) / 2;
        endIndex = (endIndex - 1) / 2;
    }
    cout << minValue << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    v = vector<long long>(N + 1, 0);
    for (int i = 1; i <= N; ++i) {
        cin >> v[i];
    }

    k = 0;
    while (pow(2, k) < N) {
        k++;
    }

    int treeLength = (int)pow(2, k + 1) - 1;
    tree = vector<long long>(treeLength + 1, LONG_LONG_MAX);
    int treeIndex = (int)pow(2, k);
    for (int i = 1; i <= N; ++i) {
        tree[treeIndex++] = v[i];
    }

    for (int i = (int)pow(2, k) - 1; i >= 1; --i) {
        tree[i] = min(tree[i * 2], tree[i * 2 + 1]);
    }

//    for (int i = 1; i <= treeLength; ++i) {
//        cout << tree[i] << " ";
//    }

    for (int i = 1; i <= M; ++i) {
        int s, e;
        cin >> s >> e;
        getMin(s, e, tree);
    }
}