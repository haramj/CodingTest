// 식의 값을 가장 최소로 만드는 법...
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string input;
    cin >> input;
    // 숫자는 최대 5자리..
    string cur = "";
    vector<int> v;
    bool curSign = true;
    for (int i = 0; i < input.size(); ++i) { // input[i] 는 char..
        if (input[i] == '+') { // +일 때
            if (!curSign){
                v.push_back((-1) * stoi(cur));
            } else v.push_back(stoi(cur));
            cur = "";
            curSign = true;
        } else if (input[i] == '-') { // -일 때
            if (!curSign){
                v.push_back((-1) * stoi(cur));
            } else v.push_back(stoi(cur));
            cur = "";
            curSign = false;
        } else { //
            cur += input[i];
        }

        if (i == input.size() - 1) {
            if (!curSign) v.push_back((-1) * stoi(cur));
            else v.push_back(stoi(cur));
        }
    }

    int curSet = 0;
    int answer = 0;
    for (int i = v.size() - 1; i >= 0; --i) {
        if (v[i] >= 0) {
            curSet += v[i];
        } else {
            answer -= (curSet + (-1) * v[i]);
            curSet = 0;
        }
    }
    if (curSet) answer += curSet;
    cout << answer;
    // 음수 뻥튀기 패턴. -> 음수일 때, 뒤에 +로 연결된 것들이면 +들로 음수를 같이 묶기. -> 음수일 때, 뒤에 -로 연결된 것들이면 괄호 안하고 그냥 다 같이 빼기.
}