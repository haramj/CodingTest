#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

static int N, M, K, k;

// b의 범위를 고려해 long long으로 유지
void update(vector<long long> &tree, long long a, long long b) {
    int index = a + (int)pow(2, k) - 1;
    long long originValue = tree[index];
    long long add = b - originValue;
    while (index >= 1) {
        tree[index] += add;
        index /= 2;
    }
}

void getSum(const vector<long long> &tree, long long s, long long e) {
    long long startIndex = s + (int)pow(2, k) - 1;
    long long endIndex = e + (int)pow(2, k) - 1;
    long long answer = 0;
    while (startIndex <= endIndex) {
        // [포인트 1] 시작 인덱스가 홀수일 때만 더하고 이동
        if (startIndex % 2 == 1) {
            answer += tree[startIndex];
            startIndex++;
        }
        // [포인트 2] 끝 인덱스가 짝수일 때만 더하고 이동
        if (endIndex % 2 == 0) {
            answer += tree[endIndex];
            endIndex--;
        }
        startIndex /= 2;
        endIndex /= 2;
    }
    cout << answer << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    if (!(cin >> N >> M >> K)) return 0;

    vector<long long> origin(N + 1, 0);
    for (int i = 1; i <= N; ++i) {
        cin >> origin[i];
    }

    k = 0;
    while (pow(2, k) < N) {
        k++;
    }

    // 인덱스를 1부터 편하게 쓰기 위해 +1 크기로 할당
    int treeLength = (int)pow(2, k) * 2; 
    vector<long long> tree(treeLength, 0);

    int index = (int)pow(2, k);
    for (int i = 1; i <= N; ++i) {
        tree[index] = origin[i];
        index++;
    }

    // [포인트 3] 트리 초기화: 리프 노드 바로 위(2^k - 1)부터 1번까지 채워야 함
    for (int i = (int)pow(2, k) - 1; i >= 1; --i) {
        long long a = 0;
        long long b = 0;
        if (i * 2 < treeLength) a = tree[i * 2];
        if (i * 2 + 1 < treeLength) b = tree[i * 2 + 1];
        tree[i] = a + b;
    }

    for (int i = 1; i <= M + K; ++i) {
        long long updateOrSum;
        long long a, b;
        cin >> updateOrSum >> a >> b;
        if (updateOrSum == 1) {
            update(tree, a, b);
        } else if (updateOrSum == 2) {
            getSum(tree, a, b);
        }
    }
    return 0;
}