// ax + by = c
// dx + ey = f
// a b c d e f
#include <iostream>

int main() {

    int a, b, c, d, e, f; // 각각 -999 ~ 999 x, y도.
    std::cin >> a >> b >> c >> d >> e >> f;
    for (int x = -999; x <= 999; ++x) {
        for (int y = -999; y <= 999; ++y) {
            if (a*x + b*y == c && d*x + e*y == f) {
                std::cout << x << " " << y;
                return 0;
            }
        }
    }
    return 0;
}