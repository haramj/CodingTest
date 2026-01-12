// M * N 의 판. 8*8 체스판 교차로 칠해져있게 최소로 칠하기.
#include <iostream>
#include <vector>

static int m[8][8] = {
        {1,0,1,0,1,0,1,0},
        {0,1,0,1,0,1,0,1},
        {1,0,1,0,1,0,1,0},
        {0,1,0,1,0,1,0,1},
        {1,0,1,0,1,0,1,0},
        {0,1,0,1,0,1,0,1},
        {1,0,1,0,1,0,1,0},
        {0,1,0,1,0,1,0,1}
};

int func(const std::vector<std::vector<int>> &v, int x, int y) {
    // x,y 는 v에서의 시작 좌표.
    int faultCount1 = 0;
    int faultCount2 = 0;

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (v[x + i][y + j] != m[i][j]) {
                faultCount1++;
            }
            if (v[x + i][y + j] != (1 - m[i][j])) {
                faultCount2++;
            }
        }
    }
    return (faultCount1 < faultCount2) ? faultCount1 : faultCount2;
}

int main() {

    int M, N; //M 세로 N 가로
    std::cin >> M >> N;
    std::vector<std::vector<int>> v(M);
    for (int i = 0; i < M; ++i) {
        std::string input;
        std::cin >> input;
        for (int j = 0; j < N; ++j) {
            if (input[j] == 'B') v[i].push_back(1);
            else v[i].push_back(0);
        }
    }

    int answer = 64;

    for (int i = 0; i <= M - 8; ++i) {
        for (int j = 0; j <= N - 8; ++j) { // i / j 는 시작점.
            int temp = func(v, i, j);
            if (temp < answer) answer = temp;
        }
    }

    std::cout << answer;
}