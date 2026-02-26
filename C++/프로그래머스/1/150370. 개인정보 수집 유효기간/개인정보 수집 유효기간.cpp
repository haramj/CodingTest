// 고객의 약관 동의 -> 1~n번으로 분류되는 개인정보 n개
// 각 약관마다 개인정보 보관 유효기간
// 당신은 각 개인정보가 어떤 약관으로 수집됐는지 알고 있습니다.
// 수집된 개인정보는 유효기간 전까지만 보관 가능하며, 유효기간이 지났다면 반드시 파기
// 오늘 날짜로 파기해야할 개인정보 번호들을 구하시오.

#include <string>
#include <vector>
#include <utility>

using namespace std;

long long timeParser(string s) {
    bool isTrue1 = true;
    bool isTrue2 = true;
    string y = "";
    string m = "";
    string d = "";
    for (int i = 0; i < s.size(); ++i) {
        if (isTrue1 && s[i] == '.'){
            isTrue1 = false;
            continue;
        }
        if (!isTrue1 && s[i] == '.') {
            isTrue2 = false;
            continue;
        }
        
        if (isTrue1 && isTrue2) {
            y += s[i];
        } else if (!isTrue1 && isTrue2) {
            m += s[i];
        } else if (!isTrue1 && !isTrue2) {
            d += s[i];
        }
    }
    
    long long answer = (stoi(y) - 1) * 12 * 28 + (stoi(m) - 1) * 28 + stoi(d);
    return answer;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> termArr(1000, 0);
    for (int i = 0; i < terms.size(); ++i) {
        bool isTrue = true;
        char p;
        string M;
        int m;
        for (int j = 0; j < terms[i].size(); ++j) {
            if (isTrue && terms[i][j] != ' ') {
                p = terms[i][j];
            } else if (isTrue && terms[i][j] == ' ') {
                isTrue = false;
            } else if (!isTrue) {
                M += terms[i][j];
            }
        }
        m = stoi(M);
        termArr[p] = m;
    }
    
    long long todayT = timeParser(today);
    vector<int> answer;
    
    for (int i = 0; i < privacies.size(); ++i) { // i + 1 번째 개인정보 확인.
        bool isTrue = true;
        string s = "";
        char p;
        for (int j = 0; j < privacies[i].size(); ++j) {
            if (privacies[i][j] == ' ') {
                isTrue = false;
                continue;
            }
            if (isTrue) {
                s += privacies[i][j];
            } else {
                p = privacies[i][j];
            }
        }
        long long t = timeParser(s);
        if (t + termArr[p] * 28 <= todayT) answer.push_back(i + 1);
    }
    return answer;
}