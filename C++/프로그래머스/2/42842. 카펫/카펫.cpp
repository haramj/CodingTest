#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    for (int i = 1; i <= 10000000; ++i) { // 가로
        for (int j = 1; j <= i; ++j) { // 세로가 가로보다 작거나 같음.
            if (i * j == brown + yellow && (i - 2) * (j - 2) == yellow) {
                answer = {i, j};
                return answer;
            }
        }
    }
    // answer[0] * answer[1] = brown + yellow 여야 함.
}