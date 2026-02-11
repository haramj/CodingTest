#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
// 임의의 자리에서 공통으로 나타나는 정수들을 이용하여 만들 수 있는 가장 큰 정수를 짝꿍이라 함.
// 없으면 -1.
// 3403 
// 13203
// => 3, 0, 3 겹침(겹치는 거 찾기). (겹치는 거 최대한 내림차순 정렬) 가장 큰 정수 330
// v.erase(v.begin() + idx) -> idx로 원소 삭제하는법
using namespace std;

string solution(string X, string Y) {
    // cout << (int)'4' - 48 << '\n';
    vector<int> v;
    vector<int> xCount = vector<int>(10, 0);
    vector<int> yCount = vector<int>(10, 0);
    for (int i = 0; i < X.size(); ++i) {
        xCount[(int)(X[i] - 48)]++;
    }
    for (int i = 0; i < Y.size(); ++i) {
        yCount[(int)(Y[i] - 48)]++;
    }
    
    string answer = "";
    bool mi = true;
    bool zero = false;
    if (xCount[0] && yCount[0]) zero = true;
    for (int i = 9; i >= 0; --i) {
        if (xCount[i] && yCount[i]) {
            if (i != 0) zero = false;
            mi = false;
            for (int j = 0; j < min(xCount[i], yCount[i]); ++j)
                answer += (char)(i + 48);
        }
    }
    if (mi) return "-1";
    if (zero) return "0";

    return answer;
}
// 100
// 203045