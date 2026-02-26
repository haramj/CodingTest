// 오늘부터 일주일 동안 각자 설정한 출근 희망 시각에 늦지 않고 출근한 직원들에게 상품을 주는 이벤트
// 출근 희망 시각 + 10분 토 일 빼고.
// 시간 : 시 * 100 + 분
// 실제로 출근한 기록을 바탕으로 상품을 받을 직원이 몇 명

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    // 타임로그를 월화수목금토일 순으로 우선 맞추기.
    // 타임로그 순회하며 만족하는 애들 ++
    // 710 2359 1050 700 650 631 659
    // 금0     토1  일   월 화   수    목
    // 4.    5.  6.  0.  1.  2.     3
    vector<vector<int>> time(timelogs.size(), vector<int>(7, 0));
    
    for (int i = 0; i < timelogs.size(); ++i) {  
        for (int j = 0; j < 7; ++j) { 
            time[i][(j + startday - 1) % 7] = timelogs[i][j];
        }
    }
    
    int answer = 0;
    
    for (int i = 0; i < time.size(); ++i) { 
        bool isTrue = true;
        for (int j = 0; j < 5; ++j) { // 월화수목금만 확인.
            int tHour = time[i][j] / 100;
            int tMin = time[i][j] % 100;
            int sHour = schedules[i] / 100;
            int sMin = schedules[i] % 100;
            if (sMin + 10 >= 60) {
                sHour++;
                sMin = sMin + 10 - 60;
            } else {
                sMin += 10;
            }
            // cout << tHour * 100 + tMin << " " << sHour * 100 + sMin << '\n'
            if (tHour * 100 + tMin > sHour * 100 + sMin) {
                isTrue = false;
                break;
            }
        }
        if (isTrue) {
            answer++;
        }
    }
    
    return answer;
}