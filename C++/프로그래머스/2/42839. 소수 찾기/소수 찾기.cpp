#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(string numbers) {
    vector<int> isPrime(10000001, 1);
    isPrime[0] = 0;
    isPrime[1] = 0;
    for (int i = 2; i * i < 10000000; ++i) {
        if (isPrime[i]){
            for (int j = i * i; j < 10000000; j += i) {
                isPrime[j] = 0;
            }
        }
    }
    int answer = 0;
    
    sort(numbers.begin(), numbers.end());
    do {
        string s = "";
        for (int i = 0; i < numbers.size(); ++i) {
            s += numbers[i];
            if (isPrime[stoi(s)] == 1) {
                answer++;
                isPrime[stoi(s)] = 2;
            }
        }
    } while (next_permutation(numbers.begin(), numbers.end()));
    
    // 12345 일 때
    // 1, 2, 3, 4, 5
    // 12 13 14 15 21 23 24 25 31 32 34 35 41 42 43 45 51 52 53 54
    // 123 ...
    return answer;
}
