#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <utility>
#include <climits>
#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<string, int> info; 

int solution(string begin, string target, vector<string> words) {
    int answer = INT_MAX;
    
    queue<info> q;
    unordered_map<string, bool> visit;
    
    q.push(info(begin, 0));
    visit[begin] = true;
    while (!q.empty()) {
        info cur = q.front(); // 현재 단어, 현재까지 변환된 횟수
        q.pop();
        if (cur.first == target) {
            if (answer > cur.second) answer = cur.second;
        }
        
        for (int i = 0; i < cur.first.size(); ++i) { // cur.first[i] 를 변환하고 나머지 끝까지 채워야지
            vector<string> temp(26, ""); // 0 ~ 25 에 i번째 인덱스를 변환한거를 다 저장.
            string tempString = "";
            for (int j = 0; j < i; ++j) { // 0 ~ i - 1 까지 temp[j] 에 저장
                tempString += cur.first[j];
            }
            for (int j = 0; j < 26; ++j) {
                temp[j] = tempString + (char)(j + 97);
            }
            
            string tempString2 = "";
            for (int j = i + 1; j < cur.first.size(); ++j) { // i + 1부터 
                tempString2 += cur.first[j];
            }
            for (int j = 0; j < 26; ++j) {
                temp[j] += tempString2;
            }
            
            for (int j = 0; j < temp.size(); ++j) {
                if (find(words.begin(), words.end(), temp[j]) != words.end()) {
                    if (!visit[temp[j]]) {
                        q.push(info(temp[j], cur.second + 1));
                        visit[temp[j]] = true;
                    }
                }
            }
        }
    }
    
    if (answer == INT_MAX) return 0;
    return answer;
}