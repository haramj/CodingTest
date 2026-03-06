#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

static int N, M;
static vector<string> v;

void dfs(int cur, int depth, vector<char> &temp) {
    temp.push_back((char)(cur + 48)); // 체크인
    temp.push_back(' '); // 체크인

    if (depth == M) { // 종료조건
        string s(temp.begin(), temp.end());
        v.push_back(s);
        return;
    }

    for (int i = 1; i <= N; ++i) { // depth 번째에 올 i.
        if (find(temp.begin(), temp.end(), (char)(i + 48)) == temp.end()) { // 없으면
            dfs(i, depth + 1, temp); // 전진
            temp.pop_back(); // 체크아웃 (백트레킹)
            temp.pop_back(); // 체크아웃 (백트레킹)
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M; // 1~N 중에 M개 뽑기

    for (int i = 1; i <= N; ++i) {
        vector<char> temp;
        dfs(i, 1, temp); // i로 시작, 깊이 1
    }

    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << '\n';
    }
    return 0;
}