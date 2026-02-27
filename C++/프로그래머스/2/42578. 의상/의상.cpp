// 다른 옷 조합해서 입기
// 하루에 최소 한 개 의상입음.
// 의상의 일부가 겹쳐도 
// 다른 의상이 겹치지 않거나 혹은 의상을 추가로 더 착용한 경우 서로 다른 방법으로 한거로 계산.
// 일단 최대한 겹치지 않는 종류로 많은 경우의 수를 계산 ... 
// 일단 해시 방식으로 종류 -> 여러 옷들 느낌으로 자료 정리 후 풀이

#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> clothes) {
    unordered_map<string, vector<string>> c; // 종류 넣으면 그 종류의 옷들 배열임.
    for (int i = 0; i < clothes.size(); ++i) {
        c[clothes[i][1]].push_back(clothes[i][0]);
    }
    int answer= 1;
    for (auto const &[k, v] : c) {
        answer *= (c[k].size() + 1);
    }
    
    return answer - 1;
}