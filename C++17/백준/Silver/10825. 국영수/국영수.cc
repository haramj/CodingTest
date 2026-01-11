// 국어점수가 감소
// 영어점수가 증가
// 수학점수가 감소
// 이름순
#include <iostream>
#include <vector>
#include <queue>

struct Info {
    std::string name;
    int korea, eng, math;
};

struct compare {
    bool operator()(const Info &g1, const Info &g2) {
        if (g1.korea == g2.korea && g1.eng == g2.eng && g1.math == g2.math) {
            return g1.name > g2.name;
        } else if (g1.korea == g2.korea && g1.eng == g2.eng){
            return g1.math < g2.math;
        } else if (g1.korea == g2.korea) {
            return g1.eng > g2.eng;
        } else {
            return g1.korea < g2.korea;
        }
    }
};

int main() {
    int N;
    std::cin >> N;

    std::priority_queue<Info, std::vector<Info>, compare> v;
    for (int i = 0; i < N; ++i) {
        Info temp = Info();
        std::cin >> temp.name >> temp.korea >> temp.eng >> temp.math;
        v.push(temp);
    }
    for (int i = 0; i < N; ++i) {
        std::cout << v.top().name << '\n';
        v.pop();
    }

}