// 디펜스 게임은 준호가 보유한 병사 n명으로 연속되는 적의 공격을 순서대로 막는 게
#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    // 우선 병사로 막기. (항상 우선순위큐에 넣으며)
    // 만일 부족할 시 우선순위큐에 top을 무적권으로 막기. ㅅㅂ... 이렇게 간단한 거를 왜 도대체 씨바
    
    priority_queue<int> q;
    int answer = 0;
    
    for (int i = 0; i < enemy.size(); ++i) {
        
        q.push(enemy[i]);
        n -= enemy[i];
        if (n >= 0) { // 일반적인 경우.
            answer++;
        } else { // 지금 얘 빼면 음수인경우.
            if (k > 0 && !q.empty()) {
                if (n + q.top() >= 0) {
                    n += q.top();
                    q.pop();
                    answer++;
                    k--;
                }
            } else {
                break;
            }
        }
    }
    
    return answer;
}