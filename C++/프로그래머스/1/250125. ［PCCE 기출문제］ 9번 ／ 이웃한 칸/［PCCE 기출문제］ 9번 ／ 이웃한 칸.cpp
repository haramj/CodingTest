#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<string>> board, int h, int w) {
    int N = board.size();
    int answer = 0;
    // dh[i]
    // dw[i]
    vector<int> dh = {0, 1, -1, 0};
    vector<int> dw = {1, 0, 0, -1};
    for (int i = 0; i < 4; ++i) {
        if (h + dh[i] >= 0 && w + dw[i] >= 0 && \
            h + dh[i] <= N - 1 && w + dw[i] <= N - 1 && \
            board[h + dh[i]][w + dw[i]] == board[h][w]) answer++;
    }
    return answer;
}

// [["blue", "red", "orange", "red"], 
//  ["red", "red", "blue", "orange"], 
//  ["blue", "orange", "red", "red"], 
//  ["orange", "orange", "red", "blue"]]