#include <string>
#include <vector>
#include <iostream>
// 첫글자 = x
// 왼 -> 오 x와 x가 아닌 다른 글자들이 나온 횟수 세기
// 같아지면 멈추기
// 두개의 문자열 분리
// 남은 부분도 위 과정 반복 (남은 부분 없을 때 까지)
// 만일 두 횟수가 다른데, 남은 부분이 없다면 지금까지 읽은 문자열 분리 하고 종료.
using namespace std;

int solution(string s) {
    int i = 0;
    int N = s.size();
    int answer = 0;
    while (i < N) {
        int first = i;
        i++;
        int x = 1;
        int notX = 0;
        if (i >= N) {
            answer++;
            return answer;
        }
        
        while (x != notX) {
            if (i >= N) {
                answer++;
                return answer;
            }
            if (s[i] == s[first]) x++;
            else notX++;
            i++;
        }
        cout << i << '\n';
        answer++;
    }
    return answer;
}