#include <string>
#include <vector>
#include <queue>

using namespace std;
// 기능 개선 작업. 100% 진도일 때 서비스에 반영
// 먼저 되는 대로가 아니고 뒤에 있는 게 먼저 개발되어도 앞에꺼 되면 같이 배포
// progresses 작업 진도
// speeds 각 작업 속도
// 각 배포마다 몇개 기능이 배포 되는지 return (배포는 하루에 한번)
// v.erase(v.begin); 0번째꺼부터 쭉 빼기
vector<int> solution(vector<int> progresses, vector<int> speeds) {
    queue<int> q;
    for (int i = 0; i < progresses.size(); ++i) q.push(i);
    
    vector<int> answer;
    int count = 0;
    while (count < progresses.size()) {
        int curDeploy = 0;
        for (int i = 0; i < speeds.size(); ++i) {
            if (speeds[i]){
                progresses[i] += speeds[i];
                if (progresses[i] >= 100) {
                    if (q.front() == i) {
                        curDeploy++;
                        speeds[i] = 0;
                        count++;
                        q.pop();
                    }
                }
            }
        }
        if (curDeploy) answer.push_back(curDeploy);
    }
    return answer;
}