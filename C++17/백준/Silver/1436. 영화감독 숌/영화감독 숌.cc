// 1 666
// 2 1666
// 3 2666
// 4 3666
// 5 4666
// 6 5666
// 7 6661
// 8 6662
// 9 6663
// 10 6664
// 11 6665
// 12 6666
// 13 6667
// 14 6668
// 15 6669
// 16 7666
// 17 8666
// 18 9666
// 19 10666
#include <iostream>

int main() {

    int N;
    std::cin >> N;

    int sixNum = 665;
    int i = 0;

    while (i < N) {
        ++sixNum;
        std::string s = std::to_string(sixNum);
        for (int k = 0; k < s.size() - 2; ++k) {
            std::string tempString = {s[k], s[k+1], s[k+2]};
            if (tempString == "666") {
                i++;
                break;
            }
        }
    }
    std::cout << sixNum;
}