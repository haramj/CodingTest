#include <iostream>
#include <vector>

int main() {

    int N;
    std::cin >> N;
    int arr[10001] = {0};
    for (int i = 0; i < N; ++i) {
        int temp;
        std::cin >> temp;
        arr[temp]++;
    }

    for (int i = 0; i < 10001; ++i) {
        if (arr[i] != 0) {
            for (int j = 0; j < arr[i]; ++j) {
                std::cout << i << '\n';
            }
        }
    }
}