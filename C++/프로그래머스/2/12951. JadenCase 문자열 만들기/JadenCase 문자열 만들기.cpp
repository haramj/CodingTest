#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";
    
    bool isTrue = true;
    // cout << (char)(65) << '\n'; +25
    // cout << (char)(97) << '\n'; + 25
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == ' ') {
            isTrue = true;
            answer += ' ';
        } else {
            if (isTrue) { // 첫자인 경우.
                if (s[i] >= 97 && s[i] <= 122) { // 소문자면 대문자로 바꾸기
                    answer += (char)(s[i] - 32);
                } else {
                    answer += s[i];
                }
                isTrue = false;
            } else {
                if (s[i] >= 65 && s[i] <= 90) { // 대문자면 소문자로 바꾸기
                    answer += (char)(s[i] + 32);
                } else {
                    answer += s[i];
                }
            }
        }
    }
    
    return answer;
}