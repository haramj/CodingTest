#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

static int k;
static vector<long long> tree;

void update(int a, long long b, vector<long long> &t) {
    // a번째를 b로 변경.
    int treeIndex = a + (int)pow(2, k) - 1;
    t[treeIndex] = b;
    while (treeIndex >= 1) {
        if (treeIndex / 2 >= 1) {
            if (treeIndex % 2 == 0) { // 현재 왼쪽자식.
                t[treeIndex / 2] = t[treeIndex] * t[treeIndex + 1] % 1000000007;
            } else {
                t[treeIndex / 2] = t[treeIndex] * t[treeIndex - 1] % 1000000007;
            }
        }
        treeIndex /= 2;
    }
}

void getMul(int s, int e, vector<long long> &t) {
    s = s + (int)pow(2, k) - 1;
    e = e + (int)pow(2, k) - 1;
    long long answer = 1;
    while (s <= e) {
        if (s % 2 == 1) answer = (answer * t[s]) % 1000000007;
        if (e % 2 == 0) answer = (answer * t[e]) % 1000000007;
        s = (s + 1) / 2;
        e = (e - 1) / 2;
    }
    cout << answer % 1000000007 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, K;
    cin >> N >> M >> K;

    vector<long long> origin(N + 1, 0);

    for (int i = 1; i <= N; ++i) {
        cin >> origin[i];
        origin[i] %= 1000000007;
    }

    k = 0;
    while (pow(2, k) < N) {
        k++;
    }
    int treeLength = (int)pow(2, k) * 2;

    tree = vector<long long>(treeLength + 1, 1);
    int treeIndex = (int)pow(2, k);
    for (int i = 1; i <= N; ++i) {
        tree[treeIndex++] = origin[i] ;
    }

    for (int i = (int)pow(2, k) - 1; i >= 1; --i) {
        tree[i] = tree[i * 2] * tree[i * 2 + 1] % 1000000007;
    }

    for (int i = 1; i <= M + K; ++i) {
        int updateOrSum, a, b;
        cin >> updateOrSum >> a >> b;
        if (updateOrSum == 1) {
            update(a, b, tree);
        } else if (updateOrSum == 2) {
            getMul(a, b, tree);
        }
    }
}