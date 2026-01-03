#include <iostream>
#include <vector>
#include <algorithm>

//int partition(std::vector<int> &v, int s, int e) {
//    int low, high;
//    int pivot = v[e];
//
//    low = s;
//    high = e - 1;
//
//    while (low <= high) {
//        while (low <= e && v[low] < pivot) low++;
//        while (high >= s && v[high] > pivot) high--;
//
//        if (low <= high) {
//            int temp = v[low];
//            v[low] = v[high];
//            v[high] = temp;
//            low++;
//            high--;
//        }
//    }
//
//    int temp = v[low];
//    v[low] = v[e];
//    v[e] = temp;
//
//    return low;
//}
//
//void quickSort(std::vector<int> &v, int s, int e) {
//    if (s >= e) return;
//    int pivot = partition(v, s, e);
//    quickSort(v, s, pivot - 1);
//    quickSort(v, pivot + 1, e);
//}

int main() {

    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N, k;
    std::cin >> N >> k;
    std::vector<int> v(N, 0);
    for (int i = 0; i < N; ++i) {
        std::cin >> v[i];
    }
    std::sort(v.begin(), v.end());
//    quickSort(v, 0, N - 1);
    std::cout << v[k - 1];
}