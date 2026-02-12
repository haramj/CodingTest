#include<string>
#include <iostream>
#include <stack>

using namespace std;
// 열린 것들은 무조건 닫혀야 함.
bool solution(string s)
{
    stack<int> st;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '(') {
            st.push(s[i]);
        } else {
            if (st.empty()) return false;
            else st.pop();
        }
    }
    if (!st.empty()) return false;
    return true;
}