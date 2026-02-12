#include <string>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

struct compare {
    bool operator()(pair<int, int> a1, pair<int, int> a2) {
        if (a1.second - a1.first == a2.second - a2.first) {
            return a1.first > a2.first;
        } else {
            return a1.second - a1.first > a2.second - a2.first;
        }
    }
};

// 오름차순 수열 -> 부분수열
// 1. 기존 수열에서 임의의 두 인덱스의 원소와 그 사이의 원소를
// 모두 포함하는 부분 수열
// 부분수열의 합은 k
// 합이 k인 부분 수열이 여러 개이면 길이가 짧은 게 우선
// 길이도 같은 게 여러 개이면 앞쪽에 나오는 수열(인덱스 작은)

vector<int> solution(vector<int> sequence, int k) {
    // 구간합 활용
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> q;
    int s = 0;
    int e = 0;
    int sum = sequence[0];
    while (s <= e && s < sequence.size() && e < sequence.size()) {
        if (sum <= k) {
            if (sum == k) {
                q.push(pair<int, int>(s, e));
            }
            e++;
            sum += sequence[e];
        } else {
            sum -= sequence[s];
            s++;
        }
    }
    
    vector<int> answer = {q.top().first, q.top().second};
    return answer;
}