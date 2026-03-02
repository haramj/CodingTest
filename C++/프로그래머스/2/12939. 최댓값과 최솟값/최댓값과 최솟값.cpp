#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> split(string s, char sep) {
    vector<int> v;
    string temp = "";
    for (int i = 0; i < s.size(); ++i) {
        
        if (s[i] == sep) {
            v.push_back(stoi(temp));
            temp = "";
        } else {
            temp += s[i];
        }
    }
    
    if (temp != "") v.push_back(stoi(temp));
    return v;
}

string solution(string s) {
    string answer = "";
    vector<int> a = split(s, ' ');
    sort(a.begin(), a.end());
    
    answer += to_string(a[0]);
    answer += " ";
    answer += to_string(a[a.size() - 1]);
    return answer;
}