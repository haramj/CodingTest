#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M; // 학생수, 키재본횟수
    vector<vector<int>> adj(N + 1);
    vector<int> D(N + 1, 0);

    for (int i = 0; i < M; ++i) {
        int t1, t2;
        cin >> t1 >> t2;
        adj[t1].push_back(t2);
    }

    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j < adj[i].size(); ++j) {
            D[adj[i][j]]++;
        }
    }

    int select;
    std::vector<int> answer;
    bool find;
    while (true) {
        find = false;
        for (int i = 1; i <= N; ++i) {
            if (D[i] == 0) {
                select = i;
                D[i]--;
                answer.push_back(select);
                find = true;
                break;
            }
        }
        if (find){
            for(int i = 0; i < adj[select].size(); ++i) {
                D[adj[select][i]]--;
            }
        } else {
            break;
        }
    }
    for (int i = 0; i < answer.size(); ++i) {
        cout << answer[i] << " ";
    }
}