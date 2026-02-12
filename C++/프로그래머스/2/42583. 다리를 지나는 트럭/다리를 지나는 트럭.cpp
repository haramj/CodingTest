#include <string>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> info; // 들어온 시간, 인덱스
// 트럭 여러대가 강을 가로지르는 일차선 다리를 정해진 순으로 건넌다.
// 모든 트럭이 다리를 건너는데 최소 몇초가 걸리는지
// 최대 bridge_length 만큼 다리에 올라갈 수 있고, weight 이하까지만 무게를 견딜 수 있음.

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int curWeight = 0;
    int curLength = 0;
    queue<info> q;
    int curIdx = 0; // 지금 넣으려는 애의 인덱스
    int count = 0; // 건넌 애 개수
    int time = 0;
    while (count < truck_weights.size()) {
        if (!q.empty() && time - q.front().first >= bridge_length){
            curWeight -= truck_weights[q.front().second];
            curLength--;
            q.pop();
            count++;
        }
        
        if (curWeight + truck_weights[curIdx] <= weight \
            && curLength + 1 <= bridge_length) { // 다리에 투입.
            q.push(info(time, curIdx));
            curWeight += truck_weights[curIdx];
            curLength++;
            curIdx++;
        }
        time++;
    }
    return time;
}