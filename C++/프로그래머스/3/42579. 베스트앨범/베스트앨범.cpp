// 장르 별로 가장 많이 재생된 노래를 두 개씩 모아 베스트 앨범
// 속한 노래가 많이 재생된 장르 -> 해당 장르 음악이 가장 많으면 그 장르 먼저 수록.
// 장르 내에서 많이 재생된 노래를 먼저 수록.
// 장르 내에서 재생 횟수가 같으면 고유번호 낮은 순 으로 수록

#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2) {
    if (p1.second == p2.second) return p1.first < p2.first;
    return p1.second > p2.second;
}

bool compare2(pair<string, int> p1, pair<string, int> p2) { // 장르 총합 배열 정렬
    return p1.second > p2.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    unordered_map<string, int> s; // 장르 총 재생 수
    unordered_map<string, vector<pair<int, int>>> m; 
    // 장르 인포 first 고유번호 second plays
    // m[장르이름][index].first 고유번호
    // m[장르이름][index].second 재생횟수
    
    for (int i = 0; i < genres.size(); ++i) {
        s[genres[i]] += plays[i];
        if (!m.count(genres[i])) {
            m[genres[i]] = {pair<int, int>(i, plays[i])};
        } else {
            m[genres[i]].push_back(pair<int, int>(i, plays[i]));
        }
    }
    
    vector<pair<string, int>> genreSum;
    for (auto const &[k, v]: m) {
        // v는 <고유번호, 재생횟수> 있는 배열.
        int temp = 0;
        for (int i = 0; i < v.size(); ++i) {
            temp += v[i].second;
        }
        genreSum.push_back(pair<string, int>(k, temp));
    }
    
    sort(genreSum.begin(), genreSum.end(), compare2); // 장르 총합 배열 정렬
    
    vector<int> answer;
    
    for (int i = 0; i < genreSum.size(); ++i) {
        string genre = genreSum[i].first;
        if (m[genre].size() == 1) {
            answer.push_back(m[genre][0].first);
        } else {
            sort(m[genre].begin(), m[genre].end(), compare);
            answer.push_back(m[genre][0].first);
            answer.push_back(m[genre][1].first);
        }
    }
    
    return answer;
}