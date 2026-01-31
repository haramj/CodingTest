// 점마다 BFS로 각각 섬 번호로 구분. (성공)
// 이후 각 섬과 섬 사이에 다리 놓기. -> 에지리스트만들기 (최소힙으로) (다리 길이 최소 2)
// 모든 섬을 연결하는 다리 길이의 최솟값 => MST 사용. (성공)
// 최소힙으로 이루진 에지리스트를 pop하면서 연결(섬개수 - 1)

#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <utility>

using namespace std;

typedef tuple<int, int, int> edge; // 0시작 1도착 2가중치
typedef pair<int, int> pos;

static vector<int> dRow = {-1, 1, 0, 0};
static vector<int> dCol = {0, 0, -1, 1};
static int N;
static int M;

struct compare {
    bool operator() (edge e1, edge e2) {
        return get<2>(e1) > get<2>(e2);
    }
};

void findIsland(vector<vector<bool>> &visit, vector<vector<int>> &mat, int i, int j, int islandNum) {
    // mat[i][j]는 방문 안 한 땅인 상태 => 여기서 BFS로 상하좌우 퍼져나가 방문안 한 땅을 모두 같은 islandNumber로 칠하기.
    queue<pos> q;
    q.push(pos(i,j));
    while (!q.empty()) {
        pos cur = q.front();
        q.pop();
        visit[cur.first][cur.second] = true;
        mat[cur.first][cur.second] = islandNum;
        for (int d = 0; d < 4; ++d) {
            int nextRow = cur.first + dRow[d];
            int nextCol = cur.second + dCol[d];
            if (nextRow >= 1 && nextRow <= N && nextCol >= 1 && nextCol <= M && !visit[nextRow][nextCol] && mat[nextRow][nextCol]) {
                q.push(pos(nextRow, nextCol));
            }
        }
    }
}

int findFunc(vector<int> &v, int n) {
    if (n == v[n]) return n;
    return v[n] = findFunc(v, v[n]);
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
    vector<vector<int>> mat(N + 1, vector<int>(M + 1, 0));

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            int t;
            cin >> t;
            mat[i][j] = t;
        }
    }

    vector<vector<bool>> visit(N + 1, vector<bool>(M + 1, false));
    int islandNum = 1;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            if (!visit[i][j] && mat[i][j]) {
                findIsland(visit, mat, i, j, islandNum);
                islandNum++;
            }
        }
    }
    islandNum--;

//    for (int i = 1; i <= N; ++i) {
//        for (int j = 1; j <= M; ++j) {
//            cout << mat[i][j] << ' ';
//        } cout << '\n';
//    }

    priority_queue<edge, vector<edge>, compare> edges;

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            if (mat[i][j]) {
                for (int d = 0; d < 4; ++d) {
                    int distance = 0;
                    int nextRow = i + dRow[d];
                    int nextCol = j + dCol[d];
                    while (nextRow >= 1 && nextRow <= N && nextCol >= 1 && nextCol <= M) {
                        if (mat[nextRow][nextCol]) { // 다리 중에 땅을 만남.
                            if (distance >= 2) {
                                edges.push(edge(mat[i][j], mat[nextRow][nextCol], distance));
                            }
                            break;
                        }
                        distance++;
                        nextRow += dRow[d];
                        nextCol += dCol[d];
                    }
                }
            }
        }
    }

    vector<int> v(islandNum + 1);
    for (int i = 1; i <= islandNum; ++i) {
        v[i] = i;
    }

    int answer = 0;
    int connectCount = 0;
    bool g = false;

    while (!edges.empty()) {
//        for (int i = 1; i <= islandNum; ++i) {
//            cout << v[i] << ' ';
//        } cout << '\n';

        edge cur = edges.top();
        edges.pop();
        if (findFunc(v, get<0>(cur)) != findFunc(v, get<1>(cur))) {
            unionFunc(v, get<0>(cur), get<1>(cur));
            connectCount++;
            answer += get<2>(cur);
            if (connectCount == islandNum - 1) {
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