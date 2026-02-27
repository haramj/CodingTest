// N 마리 포켓몬 중에 N/2 마리를 가져가도 좋다.
// 종류에 따라 번호를 포켓몬에 붙임.
// 최대한 "다양한 종류의 포켓몬" 가져가는 N/2마리 선택할 때 종류 개수의 최대값.

#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

int solution(vector<int> nums)
{
    unordered_map<int, int> m;
    for (int i = 0; i < nums.size(); ++i) {
        m[nums[i]]++;
    }
    
    int N = nums.size() / 2;
    // N개 선택하는데 가장 많이 선택.
    
    if (m.size() >= N) return N;
    else return m.size();
}