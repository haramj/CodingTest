#include <iostream>

int main() {
    int a, b, c;
    std::cin >> a >> b >> c;
    int answer = a + b - c;
    std::string s = std::to_string(a) + std::to_string(b);
    int d = std::stoi(s);
    std::cout << answer << '\n';
    std::cout << d - c;
}