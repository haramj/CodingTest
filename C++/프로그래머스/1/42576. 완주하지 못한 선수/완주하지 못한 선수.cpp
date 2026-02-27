// 한명 빼고 모두 완주
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    unordered_map<string, int> m;
    for (int i = 0; i < participant.size(); ++i) {
        m[participant[i]]++;
    }
    
    for (int i = 0; i < completion.size(); ++i) {
        m[completion[i]]++;
    }
    
    for (auto const &[k, v]: m) {
        if (v % 2) return k;
    }
}