// 각 섬들을 구분. -> 어떻게 ? => ...????? !!!!!! 이건 외우자 그냥.
// 섬 간의 거리 -> BFS(상하좌우)
#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <utility>

using namespace std;

typedef tuple<int, int, int> edge; // 0:s, 1:e, 2:w
typedef tuple<int, int, int, int> pos; // first 세로 second 가로 direct 진행방향 0그냥 1상 2하 3좌 4우 거리
typedef pair<int, int> newInfo; // first newIsland second distance

static int N;
static int M;

static vector<int> dRow = {-1, 1, 0, 0};
static vector<int> dCol = {0, 0, -1, 1};

struct compare {
    bool operator() (edge e1, edge e2) { // 오름차순 큐 최소힙
        return get<2>(e1) > get<2>(e2);
    }
};

vector<newInfo> findBridge(vector<vector<int>> &v, int i, int j) { // (i, j) // output (island, distance)
    vector<newInfo> answer = {newInfo(0,0), newInfo(0,0), newInfo(0,0), newInfo(0,0)}; // 상하좌우 순.
    for (int d = 0; d < 4; ++d) {
        int s = 0;
        int nextRow = i + dRow[d];
        int nextCol = j + dCol[d];

        while (nextRow >= 1 && nextRow <= N && nextCol >= 1 && nextCol <= M) {
            if (v[nextRow][nextCol]){ // && 막 쓰지 않기. 우선 분기 조절 후 나중에 해도 늦지 않는다.
                if (v[nextRow][nextCol] != v[i][j]) {
                    if (s >= 2) {
                        answer[d] = newInfo(v[nextRow][nextCol], s);
                    }
                }
                break;
            }
            s++;
            nextRow += dRow[d];
            nextCol += dCol[d];
        }
    }
    return answer;
}

int findFunc(vector<int> &v, int n) {
    if (n == v[n]) return n;
    else return v[n] = findFunc(v, v[n]);
}

void unionFunc(vector<int> &v, int n1, int n2) {
    int n1Top = findFunc(v, n1);
    int n2Top = findFunc(v, n2);
    if (n1Top != n2Top) v[n1Top] = n2Top;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    vector<vector<int>> v(N + 1);
    for (int i = 1; i <= N; ++i) {
        v[i].push_back(0); // 쓰레기값
        for (int j = 1; j <= M; ++j) {
            int value;
            cin >> value;
            v[i].push_back(value);
        }
    }

    int island = 0;
    // BFS 방식 활용(방문여부) + 방향벡터 활용.
    vector<vector<bool>> visit(N + 1, vector<bool>(M + 1));
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            if (v[i][j] && !visit[i][j]) { // 현재가 처음 방문한 땅인 경우. (새로운 땅)
                island++;
                queue<pair<int, int>> q;
                q.push(pair<int,int>(i, j));
                visit[i][j] = true;
                while (!q.empty()) {
                    int curRow = q.front().first;
                    int curCol = q.front().second;
                    v[curRow][curCol] = island;
                    q.pop();
                    for (int k = 0; k < 4; ++k) {
                        int nextRow = curRow + dRow[k];
                        int nextCol = curCol + dCol[k];
                        if (nextRow >= 1 && nextRow <= N && nextCol >= 1 && nextCol <= M && v[nextRow][nextCol] && !visit[nextRow][nextCol]) {
                            visit[nextRow][nextCol] = true;
                            q.push(pair<int,int>(nextRow, nextCol));
                        }
                    }
                }
            }
        }
    }

    priority_queue<edge, vector<edge>, compare> edges; // v
    vector<int> D(island + 1); // v

    for (int i = 1; i <= island; ++i) {
        D[i] = i;
    }

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            if (v[i][j]) { // v[i][j] 는 시작노드. edge(v[i][j], "BFS로 닿은 도착노드", "거리")
                vector<newInfo> temp = findBridge(v, i, j); // 상하좌우 BFS
                for (int k = 0; k < 4; ++k) {
                    if (temp[k].first) {
                        edges.push(edge(v[i][j], temp[k].first, temp[k].second));
                    }
                }
            }
        }
    }

    int connectCount = 0;
    int answer = 0;
    bool g = false;
    while (!edges.empty()) {
        edge cur = edges.top();
        edges.pop();
        if (findFunc(D, get<0>(cur)) != findFunc(D, get<1>(cur))) {
            unionFunc(D, get<0>(cur), get<1>(cur));
            connectCount++;
            answer += get<2>(cur);
            if (connectCount == island - 1) {
                g = true;
                break;
            }
        }
    }

    if (g) {
        cout << answer;
    } else {
        cout << -1;
    }
}