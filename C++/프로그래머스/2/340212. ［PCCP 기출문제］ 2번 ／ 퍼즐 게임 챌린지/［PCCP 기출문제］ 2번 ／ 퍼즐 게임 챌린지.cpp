#include <string>
#include <vector>
#include <climits>

// diff <= level 이면 그냥 time_cur 만큼 소요
// diff > level 이면 diff-level 번 틀리는데 틀리면서 time_cur만큼 소요 
// (diff-level) * (time_cur + time_prev) + time_cur;
// 퍼즐을 모두 해결하기 위한 숙련도의 최솟값
// 그럼 모두 해결하기 위한 level 을 1부터 증가시켜가면서 하기.
using namespace std;

int solution(vector<int> diffs, vector<int> times, long long limit) {
    long long s = 1;
    long long e = 100000;
    long long l;
    long long answer = e;;
    while (s <= e) {
        bool up = false;
        l = (s + e) / 2;
        long long time_prev = 0;
        long long curTime = 0; // 이번 난이도로 걸린 시간.

        for (int i = 0; i < diffs.size(); ++i) {
            if (diffs[i] > l) { // 빡실 때
                curTime += (diffs[i] - l) * (times[i] + time_prev) + times[i];
                time_prev = times[i];
            } else { // 수준에 맞을 때.
                curTime += times[i];
                time_prev = times[i];
            }
            if (curTime > limit) { // 초과 -> 즉 level 높아져야 함.
                s = l + 1;
                up = true;
                break;
            }
        }
        
        if (!up && curTime <= limit) { // 남을 or 딱 맞을 때 -> level 낮아져야 함. 가능.
            answer = l;
            e = l - 1;
        }
    }
    return answer;
}