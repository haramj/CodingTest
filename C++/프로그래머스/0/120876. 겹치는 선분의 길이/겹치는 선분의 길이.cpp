#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> lines) {
    // 범위 0 ~200 으로 만들기
    vector<int> v(201, 0);
    
    for (int i = 0; i < lines.size(); ++i) {
        // lines[i][0] ~ lines[i][1] 까지 ++
        for (int j = lines[i][0]; j < lines[i][1]; ++j) {
            v[j + 100]++;
        }
    }
    int answer = 0;
    for (int i = 0; i < 201; ++i) {
        if (v[i] >= 2) answer++;
    }
    return answer;
}