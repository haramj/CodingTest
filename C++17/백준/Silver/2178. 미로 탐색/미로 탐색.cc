// 1은 지날 수 있는 곳.
// 1.1 => N.M 위치로 이동할 때 지나야 하는 최소의 칸 수
// BFS 사용.
// 거리를 구하기 위해 원래 1 이던 곳을 이전에 있던곳 갱신된 거리 + 1 로 갱신하기.

#include <iostream>
#include <queue>
#include <vector>
#include <utility>

int main() {
    int N, M; // 세로, 가로
    std::cin >> N >> M;
    std::vector<std::vector<bool>> visit(N);
    std::vector<std::vector<int>> matrix(N);
    std::queue<std::pair<int,int>> q;

    for (int i = 0; i < N; ++i) {
        std::string temp;
        std::cin >> temp;
        for (int j = 0; j < M; ++j) {
            int t = temp[j] - '0';
            visit[i].push_back(false);
            matrix[i].push_back(t);
        }
    }

    std::pair<int, int> firstPos(0,0);
    q.push(firstPos);

    while (!q.empty()) {
        std::pair<int, int> temp = q.front();
        if (temp.first == N - 1 && temp.second == M - 1) break;

        q.pop();
        visit[temp.first][temp.second] = true;

        if (temp.first - 1 >= 0 && !visit[temp.first - 1][temp.second] && matrix[temp.first - 1][temp.second] == 1) {
            visit[temp.first - 1][temp.second] = true;
            std::pair<int, int> newPos(temp.first - 1, temp.second);
            q.push(newPos);
            matrix[temp.first - 1][temp.second] = 1 + matrix[temp.first][temp.second];
        } if (temp.first + 1 <= N - 1 && !visit[temp.first + 1][temp.second] && matrix[temp.first + 1][temp.second] == 1) {
            visit[temp.first + 1][temp.second] = true;
            std::pair<int, int> newPos(temp.first + 1, temp.second);
            q.push(newPos);
            matrix[temp.first + 1][temp.second] = 1 + matrix[temp.first][temp.second];
        } if (temp.second - 1 >= 0 && !visit[temp.first][temp.second - 1] && matrix[temp.first][temp.second - 1] == 1) {
            visit[temp.first][temp.second - 1] = true;
            std::pair<int, int> newPos(temp.first, temp.second - 1);
            q.push(newPos);
            matrix[temp.first][temp.second - 1] = 1 + matrix[temp.first][temp.second];
        } if (temp.second + 1 <= M - 1 && !visit[temp.first][temp.second + 1] && matrix[temp.first][temp.second + 1] == 1) {
            visit[temp.first][temp.second + 1] = true;
            std::pair<int, int> newPos(temp.first, temp.second + 1);
            q.push(newPos);
            matrix[temp.first][temp.second + 1] = matrix[temp.first][temp.second] + 1;
        }
    }

    std::cout << matrix[N-1][M-1];
}
