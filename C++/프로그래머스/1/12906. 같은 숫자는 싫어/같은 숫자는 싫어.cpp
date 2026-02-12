#include <vector>
#include <iostream>
#include <stack>

using namespace std;
// arr 0 ~ 9 원소로 이뤄진 배열
// 연속적으로 나타나는 숫자는 하나만 남기고 제거

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    stack<int> s;
    for (int i = 0; i < arr.size(); ++i) {
        if (!s.empty() && s.top() == arr[i]) {
            continue;
        } else if (!s.empty() && s.top() != arr[i]){
            answer.push_back(arr[i]);
            s.push(arr[i]);
        }
        
        if (s.empty()) {
            s.push(arr[i]);
            answer.push_back(arr[i]);
        }
    }

    return answer;
}