#include <iostream>
#include <vector>

using namespace std;

void preorder(vector<vector<char>> &v, char n) {
    if (n == '.') {
        return;
    } else {
        cout << n;
        preorder(v, v[n - 'A' + 1][0]);
        preorder(v, v[n - 'A' + 1][1]);
    }
}

void inorder(vector<vector<char>> &v, char n) {
    if (n == '.') {
        return;
    } else {
        inorder(v, v[n - 'A' + 1][0]);
        cout << n;
        inorder(v, v[n - 'A' + 1][1]);
    }
}

void postorder(vector<vector<char>> &v, char n) {
    if (n == '.') {
        return;
    } else {
        postorder(v, v[n - 'A' + 1][0]);
        postorder(v, v[n - 'A' + 1][1]);
        cout << n;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<vector<char>> v(27, vector<char>(2)); // 알파벳이 1~25개 25개 이므로.
    for (int i = 1; i <= N; ++i) {
        char cur, left, right;
        cin >> cur >> left >> right; // 인덱스 변환 위해서는 - 'A' 를 해야함.
//        v[cur - 'A'] => 인덱스
        v[cur - 'A' + 1][0] = left;
        v[cur - 'A' + 1][1] = right;
    }

    preorder(v, 'A');
    cout << '\n';
    inorder(v, 'A');
    cout << '\n';
    postorder(v, 'A');
}