#include <iostream>
#include <cmath>

using namespace std;
const int MAX = 10000001;
bool prime[MAX];

void sieve() {
    fill(prime + 2, prime + MAX, true);
    for (int i = 2; i * i < MAX; i++) {
        if (prime[i]) {
            for (int j = i * i; j < MAX; j += i)
                prime[j] = false;
        }
    }
}

int main() {
    long long A, B;
    cin >> A >> B;
//    long long maxN = log2(B);

    sieve();

    long long answer = 0;
    for (long long p = 2; p < MAX; p++) {
        if (prime[p]) {
            long long temp = p;

            while (temp <= B / p) {
                temp *= p;
                if (temp >= A) answer++;
            }
        }
    }
    cout << answer;
}