#include <iostream>
#include <queue>
#include <algorithm>

static bool visit[201][201]; // [A][B]의 값만 정하고 c는 알아서 "C - (a + b)"로 정해지므로.
static std::vector<int> answer;

void BFS(int A, int B, int C) {
    std::queue<std::pair<int, int>> q;
    int maxWater[3] = {A, B, C};
    int give[6] = {0, 0, 1, 1, 2, 2};
    int receive[6] = {1, 2, 0, 2, 0, 1};

    std::pair<int, int> first = std::pair<int,int>(0,0);
    q.push(first);
    visit[0][0] = true;
    answer.push_back(C);

    while (!q.empty()) {
        std::pair<int, int> current = q.front();
        std::pair<int, int> next;
        int water[3] = {current.first, current.second, C - (current.first + current.second)};
//        std::cout << water[0] << " " << water[1] << " " << water[2] << '\n';
        q.pop();
        for (int i = 0; i < 6; ++i) {
            if (water[give[i]] + water[receive[i]] <= maxWater[receive[i]]) {
                int nextWater[3] = {current.first, current.second, C - (current.first + current.second)};
                nextWater[give[i]] = 0;
                nextWater[receive[i]] = water[give[i]] + water[receive[i]];
//                std::cout << nextWater[0] << " " << nextWater[1] << " " << nextWater[2] << '\n';
                next.first = nextWater[0];
                next.second = nextWater[1];
                if (!visit[next.first][next.second]) {
                    q.push(next);
                    visit[next.first][next.second] = true;
                    if (next.first == 0){
                        answer.push_back(C - (next.first + next.second));
                    }
                }
            } else {
                int nextWater[3] = {current.first, current.second, C - (current.first + current.second)};
                nextWater[give[i]] = water[give[i]] + water[receive[i]] - maxWater[receive[i]];
                nextWater[receive[i]] = maxWater[receive[i]];
//                std::cout << nextWater[0] << " " << nextWater[1] << " " << nextWater[2] << '\n';
                next.first = nextWater[0];
                next.second = nextWater[1];
                if (!visit[next.first][next.second]) {
                    q.push(next);
                    visit[next.first][next.second] = true;
                    if (next.first == 0){
                        answer.push_back(C - (next.first + next.second));
                    }
                }
            }
        }
    }
}

int main() {
    int A, B, C;
    std::cin >> A >> B >> C;
    BFS(A,B,C);
    std::sort(answer.begin(), answer.end());
    for (int i = 0; i < answer.size(); ++i) {
        if (i ==0) std::cout << answer[i] << " ";
        else if (i > 0 && answer[i - 1] != answer[i])
            std::cout << answer[i] << " ";
    }
}