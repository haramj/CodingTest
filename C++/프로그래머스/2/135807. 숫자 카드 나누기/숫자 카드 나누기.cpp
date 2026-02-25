// 숫자가 하나씩 적힌 카드들을 절반씩 나눠서 가진 후, 다음 두 조건 중 하나를 만족하는 가장 큰 양의 정수 a의 값
// 철수꺼 모두 나눌 수 있음. 영희는 하나도 나눌 수 없음.
// 영희꺼 모두 나눌 수 있음. 철수꺼 하나도 나눌 수 없음.
// 가장 큰 양의 정수 a

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    // arrayA는 다 나눠짐 arrayB는 다 나누어 안 떨어짐.
    sort(arrayA.begin(), arrayA.end());
    sort(arrayB.begin(), arrayB.end());
    int aMax = arrayA[arrayA.size() - 1];
    int bMax = arrayB[arrayB.size() - 1];
    int lim = (aMax > bMax) ? aMax : bMax; // 어디까지 나눠볼건지. 최대중에 a,b중 작은거.
    for (int i = 1; i <= lim; ++i) { 
        bool isTrue = true;
        for (int j = 0; j < arrayA.size(); ++j) { // arrayA에 모두 나누어떨어지는 애 찾기.
            if (arrayA[j] % i) { // i 는 arrayA중에 나누어떨어지지 않는 게 있음.
                isTrue = false;
                break;
            }
        }
        
        if (isTrue) { // i 가 arrayB에 모두 나누어떨어지지 않는 애 찾기.
            bool isTrue2 = true;
            for (int j = 0; j < arrayB.size(); ++j) {
                if (arrayB[j] % i == 0) { // 나누어떨어짐. 절대 안 됨.
                    isTrue2 = false;
                    break;
                }
            }
            
            if (isTrue2) {
                if (answer < i) answer = i; 
            }
        }
    }
    
    for (int i = 1; i <= lim; ++i) { 
        bool isTrue = true;
        for (int j = 0; j < arrayB.size(); ++j) { // arrayA에 모두 나누어떨어지는 애 찾기.
            if (arrayB[j] % i) { // i 는 arrayA중에 나누어떨어지지 않는 게 있음.
                isTrue = false;
                break;
            }
        }
        
        if (isTrue) { // i 가 arrayB에 모두 나누어떨어지지 않는 애 찾기.
            bool isTrue2 = true;
            for (int j = 0; j < arrayA.size(); ++j) {
                if (arrayA[j] % i == 0) { // 나누어떨어짐. 절대 안 됨. 근데 i가 array
                    isTrue2 = false;
                    break;
                }
            }
            
            if (isTrue2) {
                if (answer < i) answer = i; 
            }
        }
    }
    return answer;
}