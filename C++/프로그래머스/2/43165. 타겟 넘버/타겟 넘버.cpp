#include <string>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

typedef pair<int, int> info; // 0 누적 값 1 현재까지 처리된 인덱스

int solution(vector<int> numbers, int target) {
    
    // 어차피 다 봐야함.
    // -> 이전 값 기억해야 함.
    int answer = 0;
    queue<info> q;
    q.push(info(numbers[0], 0));
    q.push(info((-1) * numbers[0], 0));
    while (!q.empty()) {
        info cur = q.front();
        q.pop();
        if (cur.second == numbers.size() - 1) { // 끝까지 옴.
            if (target == cur.first) answer++;
        } else {
            q.push(info((-1) * numbers[cur.second + 1] + cur.first, cur.second + 1));
            q.push(info(numbers[cur.second + 1] + cur.first, cur.second + 1));
        }
    }
    
    return answer;
}