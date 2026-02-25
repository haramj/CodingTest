//  프로그래머스에서 작성했던 코드는 그 문제에 가서 다시 볼 수 있기 때문에 저장해 둔 파일들을 전부 삭제
// 바탕화면의 상태를 나타낸 문자열 배열 wallpaper가
// 최소한의 이동거리를 갖는 한번의 드래그로 모든파일선택 한 번에 지우기.
// 왼쪽버튼 누르고 S -> E 로 이동 후 왼쪽 버튼 떼기

#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <cmath>

using namespace std;
typedef pair<int, int> pos;

struct compare1 { // row
    bool operator() (pos p1, pos p2) { 
        return p1.first > p2.first; //row 오름차순
    }
};

struct compare2 { // col
    bool operator() (pos p1, pos p2) { 
        return p1.second > p2.second; //col 오름차순
    }
};

vector<int> solution(vector<string> wallpaper) {
    // {row 가장 작은애, col 가장 작은 애, row 가장 큰 애, col 가장 큰 애}
    priority_queue<pos, vector<pos>, compare1> q1;
    priority_queue<pos, vector<pos>, compare2> q2;
    for (int i = 0; i < wallpaper.size(); ++i) {
        for (int j = 0; j < wallpaper[i].size(); ++j) {
            if (wallpaper[i][j] == '#') {
                q1.push(pos(i, j));
                q2.push(pos(i, j));
            }
        }
    }
    
    int a1 = q1.top().first; // row 가장 작은 애
    int a2 = q2.top().second; // col 가장 작은 애
    q1.pop();
    q2.pop();
    if (q1.empty()) {
        vector<int> answer = {a1, a2, a1 + 1, a2 + 1};
        return answer;
    }
    
    int a3, a4; // row 가장 큰 애 col 가장 큰 애
    while (!q1.empty()) {
        a3 = q1.top().first;
        a4 = q2.top().second;
        q1.pop();
        q2.pop();
    }
    
    
    vector<int> answer = {a1,a2,a3 + 1,a4 + 1};
    return answer;
}