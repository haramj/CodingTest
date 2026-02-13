#include <string>
#include <vector>
#include <climits>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int maxW = 0;
    int maxH = 0;
    for (int i = 0; i < sizes.size(); ++i) {
        if (sizes[i][0] > sizes[i][1]) {
            int temp = sizes[i][0];
            sizes[i][0] = sizes[i][1];
            sizes[i][1] = temp;
        }
        
        if (sizes[i][0] > maxW) {
            maxW = sizes[i][0];
        }
        if (sizes[i][1] > maxH) {
            maxH = sizes[i][1];
        }
    }
    return maxW * maxH;
}
// 가로 >