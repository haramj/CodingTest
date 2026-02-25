// 같은 시간대에 게임을 이용하는 사람이 m명 늘어날 때마다 서버 1대가 추가로 필요합니다.  m당 1대
// 어느 시간대의 이용자가 n x m명 이상 (n + 1) x m명 미만이라면 최소 n대의 증설된 서버가 운영 중
// 한 번 증설한 서버는 k시간 동안 운영하고 그 이후에는 반납
// k=5면 10시증설 -> 15시까지 운영.
// 최소 몇 번 증설해야 하는지.

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> players, int m, int k) {
    int cur = 0;
    int answer = 0;
    vector<int> server(24, 0); // 남은 일, 얼마나 추가 되었는지
    for (int i = 0; i < players.size(); ++i) {
        // 0 ~ i 번째 까지 지금 증설되었으면 값이 있음.
        cur = 0; 
        for (int j = 0; j < i; ++j) { // 현재 총 서버 수.
            if (i - j < k) {
                cur += server[j];
            }
        }
        int n = cur;
        int count = 0; //추가 증설
        if (n * m <= players[i]) {
            while ((n + 1) * m  <= players[i]) {
                n++; // 지금 서버 수
                count++;
            }
        }
        // cout << count << '\n';
        answer += count;
        if (count) {
            server[i] = count; // 남은 시간
        }
    }
    return answer;
}