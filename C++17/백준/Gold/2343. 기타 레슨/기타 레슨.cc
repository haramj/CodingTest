// 블루레이의 크기는 모두 같은 크기.
// 1번 블루레이에 1,2,3,4,5
// 2번 블루레이에 6,7
// 3번 블루레이에 8,9 를 넣으면 각각 15, 13, 17이 된다. 이때 모든 블루레이의 크기는 같아야 하므로 17.
// 17보다 더 작은 크기를 가지는 블루레이를 만들 수 없다.
#include <iostream>
#include <vector>

int main() {
    int N, M, sum = 0;
    std::cin >> N >> M;
    std::vector<int> v(N);
    int maxVideoLength = 0;
    for (int i = 0; i < N; ++i) {
        std::cin >> v[i];
        if (i == 0) maxVideoLength = v[i];
        if (maxVideoLength < v[i]) maxVideoLength = v[i];
        sum += v[i];
    }
    // 총합 45 그 중 블루레이 개수인 3으로 나누면 모두 평균적으로 15로 들어가는 게 좋음.
    // 블루레이의 크기는 (강의길이의최대)9 ~ (모든강의의총길이)45
    // 만일 블루레이 크기가 부족하면 시작값을 증가 / 블루레이 크기가 남으면 끝값을 감소.
    int s = maxVideoLength;
    int e = sum;
    int midValue;
    bool full;
    int answer;

    // 중앙값으로 블루레이에 값을 다 채울 수 있으면 s 를 갱신 (뒷 셋)
    // 중앙값으로 블루레이에 값을 다 못채우면 e 를 갱신 (앞 셋)
    while (s <= e) {
        full = false;
        std::vector<int> blueRay(M, 0);
        int blueRayIndex = 0;
        midValue = (s + e) / 2;
        for (int i = 0; i < N; ++i) {
            if (blueRayIndex > M - 1) {
                s = midValue + 1;
                full = true;
                break;
            }
            if (blueRay[blueRayIndex] + v[i] > midValue){
                blueRayIndex++;
                if (blueRayIndex > M - 1) {
                    s = midValue + 1;
                    full = true;
                    break;
                }
                blueRay[blueRayIndex] += v[i];
            } else {
                blueRay[blueRayIndex] += v[i];
            }
        }

        if (!full) {
            e = midValue - 1;
        }

        if (blueRayIndex <= M - 1) {
            int maxRay = blueRay[0];
            for (int i = 1; i < M; ++i) {
                if (maxRay < blueRay[i]) maxRay = blueRay[i];
            }
//            std::cout << maxRay << '\n';
//            for (int j = 0; j < M; ++j) {
//                std::cout << blueRay[j] << " ";
//            } std::cout << '\n';
            if (answer == 0) answer = maxRay;

            if (answer > maxRay) {
                answer = maxRay;
            }
        }


    }
    std::cout << answer;
}