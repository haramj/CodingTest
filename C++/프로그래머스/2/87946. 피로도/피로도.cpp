#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
// 0 1 2
int solution(int k, vector<vector<int>> dungeons) {
    int size = dungeons.size();
    string s = "";
    for (int i = 0; i < size; ++i) {
        s += (char)(i + 48);
    }
    sort(s.begin(), s.end());
    int answer = 0;
    do {
        int curK = k;
        int count = 0;
        for (int i = 0; i < s.size(); ++i) {
            int cur = (int)(s[i] - 48);
            if (curK >= dungeons[cur][0]) {
                curK -= dungeons[cur][1];
                count++;
            } else {
                break;
            }
        }
        if (count > answer) answer = count;
    } while(next_permutation(s.begin(), s.end()));
    return answer;
}

// 최소 필요 피로도가 높은 순으로 -> 같으면 소모피로도 낮으면서 