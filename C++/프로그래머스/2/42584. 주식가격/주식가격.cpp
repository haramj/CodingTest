#include <string>
#include <vector>
#include <queue>
#include <utility>

using namespace std;
// 초단위로 기록된 주식 가격이 담긴 prices 
// 가격 안 떨어지는 기간 몇초?
// [1, 2, 3, 2, 3]	
// 1초일 때 1원 => 끝까지 1원보다 안 떨어짐 (4일지속).
// 2초일 때 2원 => 끝까지 2원보다 안 떨어짐 (3일지속).
// 3초일 때 3원 => 1초 뒤에 떨어짐
// 4초일 때 2원 => 끝까지 안 떨어짐 (1일지속)
// 5초일 때 3원.=> 0일지속
// [4, 3, 1, 1, 0]

typedef pair<int, int> info; // first 산 가격, second 산 날.

vector<int> solution(vector<int> prices) {
    priority_queue<info> q;
    vector<int> answer(prices.size(), 0);
    for (int i = 0; i < prices.size(); ++i) {
        while (!q.empty() && prices[i] < q.top().first) {
            // q.top() 인 애는 오늘 떨어진 애임.
            answer[q.top().second] = i - q.top().second;
            q.pop();
        }
        q.push(info(prices[i], i));
    }
    for (int i = 0; i < prices.size(); ++i) {
        if (answer[i] == 0) answer[i] = prices.size() - i - 1;
    }
    return answer;
}