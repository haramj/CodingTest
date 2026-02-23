// 단, 엘리베이터가 위치해 있는 층과 버튼의 값을 더한 결과가 0보다 작으면 엘리베이터는 움직이지 않습니다.
// 0층이 가장 아래 층.
// 버튼 한 번당 돌 1개 소모.
// 최소한의 버튼으로 이동.
// 그리디 씨발람
#include <string>
#include <vector>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(int storey) {
    int answer = 0;
    while (storey > 0) {
        int cur = storey % 10;
        int next = storey / 10 % 10;
        if (cur > 5) {
            answer += 10 - cur;
            storey += 10;
        } else if (cur < 5) {
            answer += cur;
        } else {
            answer += 5;
            if (next >= 5) {
                storey += 10;
            }
        }
        storey /= 10;
    }
    return answer;
}
