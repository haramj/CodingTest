#include <iostream>
#include <vector>

static std::vector<bool> truth;

int findFunc(std::vector<int> &v, int n) {
    if (v[n] == n) {
        return v[n];
    } else {
        return v[n] = findFunc(v, v[n]);
    }
}

void unionFunc(std::vector<int> &v, int n1, int n2) {
    int n1Top = findFunc(v, n1);
    int n2Top = findFunc(v, n2);
    if (n1Top != n2Top) {
        v[n1Top] = n2Top;
        if (truth[n1Top] || truth[n2Top]) {
            truth[n2Top] = true;
            truth[n1Top] = true;
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N, M; // 사람수, 파티수
    int answer= 0;
    std::cin >> N >> M;
    std::vector<int> v(N + 1);
    for (int i = 1; i <= N; ++i) {
        v[i] = i;
    }
    std::vector<int> partyRepresent;
    int K; // 진실을 아는 사람 수.
    truth = std::vector<bool>(N + 1, false);
    std::cin >> K;
    for (int i = 0; i < K; ++i) {
        int temp;
        std::cin >> temp;
        truth[temp] = true;
    }

    for (int i = 0; i < M; ++i) { // 파티수 만큼 반복.
        // 한 파티에 있는 애들 union 연산.
        int numberOfPerson;
        std::cin >> numberOfPerson;
        std::vector<int> partyPerson;
        for (int j = 0; j < numberOfPerson; ++j) {
            int temp;
            std::cin >> temp;
            partyPerson.push_back(temp);
        }
        for (int j = 1; j < numberOfPerson; ++j) {
            unionFunc(v, partyPerson[j], partyPerson[j - 1]);
        }
        partyRepresent.push_back(partyPerson[0]);
    }

    for (int i = 0; i < M; ++i) {
        if (!truth[findFunc(v,partyRepresent[i])]) {
            answer++;
        }
    }
    std::cout << answer;
}