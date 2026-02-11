#include <string>
#include <vector>

// 빵 야채 고기 빵 순서
// 빵1 야채2 고기3
// 1 2 3 1 => 햄버거 하나!
using namespace std;

int solution(vector<int> ingredient) {
    
    int answer = 0;
    vector<int> s; // 스택 역할할 벡터
    for (int i = 0; i < ingredient.size(); ++i) {
        s.push_back(ingredient[i]);
        if (s.size() >= 4) {
            if (s[s.size() - 4] == 1 && s[s.size() - 3] == 2 \
                && s[s.size() - 2] == 3 && s[s.size() - 1] == 1) {
                answer++;
                s.pop_back();
                s.pop_back();
                s.pop_back();
                s.pop_back();
            }
        }
    }
    return answer;
}