#include <string>
#include <vector>
#include <climits>
#include <iostream>
// 자판 키 개수 1~100
// 키에 할당 안 된 경우 있음.
// 최소 몇 번 누러야 그 문자열을 작성할 수 있는지.
using namespace std;
// keymap 자판
// targets 만들 문자열
vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    for (int i = 0; i < targets.size(); ++i) {
        // targets[i] - 현재 만들어야 되는 문자열.
        int pushCount = 0;
        bool notMake = false;
        // 한 문자를 몇번 눌러야 최소인지 찾고 pushCount 에 추가.
        for (int j = 0; j < targets[i].size(); ++j) {
            // targets[i][j] // 현재 눌러야되는 문자.
            int minCharCount = INT_MAX;
            for (int k = 0; k < keymap.size(); ++k) {
                for (int l = 0; l < keymap[k].size(); ++l) {
                    // keymap[k][l] 현재 k를 l+1번 눌렀을 때 나오는 애
                    if (keymap[k][l] == targets[i][j]) {
                        if (minCharCount > l + 1) minCharCount = l + 1;
                    }
                }
            }
            if (minCharCount != INT_MAX) pushCount += minCharCount;
            else {
                notMake = true;
                break;
            }
        }
        if (notMake) answer.push_back(-1);
        else answer.push_back(pushCount);
    }
    return answer;
}