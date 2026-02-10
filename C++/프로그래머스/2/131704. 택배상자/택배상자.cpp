#include <string>
#include <vector>
#include <stack>
#include <queue>

// 컨테이너 - 큐
// 보조 컨테이너 - 스택
// 4 3 1 2 5 로 배달 해야 함.
// 1,2,3 보조
// 4 실기.(컨테이너) 
// 3 실기.(보조)
// 1 실어야 하지만, 보조 / 컨테이너 다 없음. 2개까지. 실을 수 있다.
using namespace std;

int solution(vector<int> order) {
    queue<int> mainCon;
    for (int i = 1; i <= order.size(); ++i) mainCon.push(i);
    stack<int> subCon;
    int answer = 0;
    for (int i = 0; i < order.size(); ++i) {
        //order[i] // 현재 실어야 하는 애
        int cur = order[i];
        // while (!subCon.empty() && cur != subCon.top()) {
        //     subCon
        // }
        if (!subCon.empty() && subCon.top() == cur) {
            subCon.pop();
            answer++;
            continue;
        }
        while (!mainCon.empty() && cur != mainCon.front()) {
            subCon.push(mainCon.front());
            mainCon.pop();
        }
        if (!mainCon.empty() && cur == mainCon.front()) {
            mainCon.pop();
            answer++;
            continue;
        }
        break;
    }
    return answer;
}