#include <iostream>
#include <vector>
#include <numeric>

std::vector<int> parent;

// find_set: v가 속한 집합의 대표(루트)를 찾습니다.
// 경로 압축(path compression)을 사용하여 성능을 최적화
int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

// union_sets: a와 b가 속한 집합을 병합.
// 이 문제에서는 비행기를 게이트에 '도킹'하는 데 사용
void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        parent[a] = b;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int G, P;
    std::cin >> G >> P;

    // DSU 초기화: 1-기반 인덱싱을 위해 G+1 크기로 설정
    parent.resize(G + 1);
    // 각 게이트를 초기에는 독립적인 집합으로
    std::iota(parent.begin(), parent.end(), 0);

    int docked_planes = 0;
    for (int i = 0; i < P; ++i) {
        int g;
        std::cin >> g;

        // g번 게이트까지의 범위에서 가장 높은 번호의 사용 가능한 게이트를 찾음.
        int available_gate = find_set(g);

        // 만약 대표 게이트가 0이라면, 1번부터 g번까지의 모든 게이트가 꽉 찼다는 의미.
        // 더 이상 비행기를 도킹할 수 없으므로 반복문을 종료.
        if (available_gate == 0) {
            break;
        }

        // 비행기를 도킹하고, 현재 게이트를 '사용 불가능'으로 표시하기 위해
        // 현재 게이트 집합을 그 바로 아래 번호의 게이트 집합과 병합
        union_sets(available_gate, available_gate - 1);
        docked_planes++;
    }

    std::cout << docked_planes << std::endl;

    return 0;
}
