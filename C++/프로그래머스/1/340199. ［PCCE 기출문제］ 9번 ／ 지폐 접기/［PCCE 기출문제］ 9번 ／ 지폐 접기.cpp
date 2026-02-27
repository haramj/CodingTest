// 길이가 긴 쪽을 반으로 접는다.
// 접기 전 길이 홀수면, 소수점 이하는 버린다
// 접힌 지폐를 그대로 or 90도 돌려서 넣을 수 있다면 그만 접기.
// 최소 몇번 접어야 하는지

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> wallet, vector<int> bill) {
    int answer = 0;
    while (min(bill[0], bill[1]) > min(wallet[0], wallet[1]) \
          || max(bill[0], bill[1]) > max(wallet[0], wallet[1])) {
        // cout << bill[0] << " " << bill[1] << '\n';
        if (bill[0] > bill[1]) {
            bill[0] /= 2;
        } else {
            bill[1] /= 2;
        }
        answer++;
    }
    return answer;
}