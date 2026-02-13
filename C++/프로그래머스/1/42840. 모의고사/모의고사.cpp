#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> a = {1,2,3,4,5};
    vector<int> b = {2,1,2,3,2,4,2,5};
    vector<int> c = {3,3,1,1,2,2,4,4,5,5};
    vector<int> score = vector<int>(3, 0);
    for (int i = 0; i < answers.size(); ++i) {
        score[0] += (int)(answers[i] == a[i % 5]);
        score[1] += (int)(answers[i] == b[i % 8]);
        score[2] += (int)(answers[i] == c[i % 10]);
    }
    int maxScore = max({score[0], score[1], score[2]});
    vector<int> answer;
    for (int i = 0; i < 3; ++i) {
        if (maxScore == score[i]) {
            answer.push_back(i + 1);
        }
    }
    return answer;
}
// 1 2 3 4 5
// 2 1 2 3 2 4 2 5
// 3 3 1 1 2 2 4 4 5 5