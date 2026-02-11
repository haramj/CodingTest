#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string s, string skip, int index) {
    // cout << 'z' - 0 << '\n'; // 97 ~ 122
    // cout << (char)(65) << '\n';
    // s = "abcdef";
    // skip =  "ghij";
    // index = 4;
    string answer = "";
    for (int i = 0; i < s.size(); ++i) {
        char cur = s[i];
        for (int j = 0; j < index; ++j) {
            bool isSkip = true;
            while (isSkip) {
                if (cur == 'z') cur = 'a';
                else cur++;
                if (find(skip.begin(), skip.end(), cur) == skip.end()) {
                    isSkip = false;
                }
            }
        }
        answer += cur;
    }
    return answer;
}