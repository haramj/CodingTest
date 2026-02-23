// 무게와 <시소축-좌석간거리> 곱이 양쪽이 같으면 시소짝꿍
// r1m1 == r2m2 이면 시소짝꿍
// r은 2,3,4

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

long long solution(vector<int> weights) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int> visit(1001, false);
    long long answer = 0;
    bool isD = false;
    sort(weights.begin(), weights.end());
    for (int i = 0; i < weights.size() - 1; ++i) {
        for (int j = i + 1; !isD && j < weights.size(); ++j) {
            bool isD = false;
            // 무게가 1 : 1인 경우 1 : 2인 경우 2 : 3인경우 3 : 4인경우
            if (weights[i] == weights[j]) isD = true;
            else if (weights[i] * 2 == weights[j]) isD = true;
            else if (weights[i] * 3 == weights[j] * 2) isD = true;
            else if (weights[i] * 4 == weights[j] * 3) isD = true;
            if (isD) answer++;
        }
    }
    return answer;
}