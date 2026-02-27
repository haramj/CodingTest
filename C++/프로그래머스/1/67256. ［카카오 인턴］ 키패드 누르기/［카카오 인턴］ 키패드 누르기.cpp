#include <string>
#include <vector>
#include <utility>
#include <iostream>

using namespace std;

typedef pair<int, int> pos;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    vector<vector<int>> board(4, vector<int>(3, 0));
    int temp = 1;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i][j] = temp;
            temp++;
        }
    }
    
    board[3][0] = -1; // 별
    board[3][1] = 0;
    board[3][2] = -2; // 샵
    
    pos left = pos(3, 0); // 별 위치
    pos right = pos(3, 2); // 샵 위치
    for (int i = 0; i < numbers.size(); ++i) {
        if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7) {
            answer += 'L';
            left.first = numbers[i] / 3;
            left.second = 0;
        } else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9) {
            answer += 'R';
            right.first = numbers[i] / 3 - 1;
            right.second = 2;
        } else {
            pos nextPos;
            if (numbers[i] == 0) {
                nextPos = pos(3,1);
            } else {
                nextPos = pos(numbers[i] / 3, 1);
            }
            
            int leftDistance = ((nextPos.first - left.first >= 0) ? (nextPos.first - left.first) : (-1)*(nextPos.first - left.first)) + ((nextPos.second - left.second >= 0) ? (nextPos.second - left.second) : (-1)*(nextPos.second - left.second));
            int rightDistance = ((nextPos.first - right.first >= 0) ? (nextPos.first - right.first) : (-1)*(nextPos.first - right.first)) + ((nextPos.second - right.second >= 0) ? (nextPos.second - right.second) : (-1)*(nextPos.second - right.second));
            
            if (leftDistance > rightDistance) {
                answer += 'R';
                right.first = nextPos.first;
                right.second = nextPos.second;
            } else if (leftDistance < rightDistance) {
                answer += 'L';
                left.first = nextPos.first;
                left.second = nextPos.second;
            } else {
                if (hand == "right") {
                    answer += 'R';
                    right.first = nextPos.first;
                    right.second = nextPos.second;
                } else {
                    answer += 'L';
                    left.first = nextPos.first;
                    left.second = nextPos.second;
                }
            }
            
//             // 왼손 오른손 거리 구하기 numbers[i]까지
        }
    }
    
    return answer;
}