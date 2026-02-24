#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    vector<int> s(1440, 0); // 누적합 배열
    vector<vector<int>> v; // 바꾼 배열 분으로
    for (int i = 0; i < book_time.size(); ++i) {
        // book_time[i][0] / book_time[i][1]
        int start = ((int)(book_time[i][0][0] - 48) * 10 + (int)(book_time[i][0][1] - 48)) * 60 + (int)(book_time[i][0][3] - 48) * 10 + (int)(book_time[i][0][4] - 48);
        int end = ((int)(book_time[i][1][0] - 48) * 10 + (int)(book_time[i][1][1] - 48)) * 60 + (int)(book_time[i][1][3] - 48) * 10 + (int)(book_time[i][1][4] - 48) + 10;
        vector<int> temp = {start, end};
        v.push_back(temp);
    };
    
    for (int i = 0; i < 1440; ++i) {
        for (int j = 0; j < v.size(); ++j) {
            // v[j][0] i v[j][1] 시작분 끝나는분 이 사이에 i가 있으면 s[i]++;
            if (v[j][0] <= i && i < v[j][1]) {
                s[i]++;
            }
        }
        if (s[i] > answer) answer = s[i];
    }
    
    return answer;
    // 동일한 시간대 예약 개수 중 최대값.
}