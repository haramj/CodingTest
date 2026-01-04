#include <iostream>
#include <vector>

static std::vector<int> v;
static std::vector<int> temp;

void mergeSort(int s, int e) {
    if (s >= e) {
        return;
    }

    int m = (s + e) / 2;
    mergeSort(s, m);
    mergeSort(m + 1, e);

    for (int i = s; i <= e; ++i) {
        temp[i] = v[i];
    }

    int k = s;
    int index1 = s;
    int index2 = m + 1;

    while (index1 <= m && index2 <= e) {
        if (temp[index1] < temp[index2]) {
            v[k] = temp[index1];
            index1++;
            k++;
        } else {
            v[k] = temp[index2];
            index2++;
            k++;
        }
    }

    while (index1 <= m) {
        v[k] = temp[index1];
        index1++;
        k++;
    }
    while (index2 <= e) {
        v[k] = temp[index2];
        index2++;
        k++;
    }
}

int main() {

    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N;
    std::cin >> N;
    v = std::vector<int>(N, 0);
    temp = std::vector<int>(N, 0);

    for (int i = 0; i < N; ++i) {
        std::cin >> v[i];
    }

    mergeSort(0, N - 1);

    std::cout << v[0];
    for (int i = 1; i < N; ++i) {
        std::cout << '\n' << v[i];
    }
}