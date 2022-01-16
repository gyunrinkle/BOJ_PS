#include <iostream>
#include <queue>
#include <tuple>

using namespace std;
const int MAX_LEN = 100;
int N, cnt = 0, cntGR = 0;
char matrix[MAX_LEN][MAX_LEN];
int dist[MAX_LEN][MAX_LEN];
int di[4] = {-1, 1, 0, 0};
int dj[4] = {0, 0, -1 ,1};

void initDist() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            dist[i][j] = -1;
        }
    }//dist 배열 초기화
}
bool findPath(pair<int, int> start) {
    if (dist[start.first][start.second] != -1)  return false;
    queue<pair<int, int>> q;
    q.push(start);
    while(!q.empty()) {
        int ci, cj;
        tie(ci, cj) = q.front();
        q.pop();

        if (dist[ci][cj] == -1) {
            dist[ci][cj] = 1;
            for (int k = 0; k < 4; k++) {
                int ni, nj;
                tie(ni, nj) = make_pair(ci + di[k], cj + dj[k]);
                if (ni < 0 || ni >= N || nj < 0 || nj >= N) continue;
                if (matrix[ni][nj] != matrix[ci][cj]) continue;
                if (dist[ni][nj] == -1) {
                    q.push({ni, nj});
                }
            }
        }
    }

    return true;
}
bool findPathGR(pair<int, int> start) {
    if (dist[start.first][start.second] != -1)  return false;
    queue<pair<int, int>> q;
    q.push(start);
    while(!q.empty()) {
        int ci, cj;
        tie(ci, cj) = q.front();
        q.pop();

        if (dist[ci][cj] == -1) {
            dist[ci][cj] = 1;
            for (int k = 0; k < 4; k++) {
                int ni, nj;
                tie(ni, nj) = make_pair(ci + di[k], cj + dj[k]);
                if (ni < 0 || ni >= N || nj < 0 || nj >= N) continue;
                if (matrix[ni][nj] + matrix[ci][cj] == 148 || matrix[ni][nj] + matrix[ci][cj] == 137) continue;
                if (dist[ni][nj] == -1) {
                    q.push({ni, nj});
                }
            }
        }
    }

    return true;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> matrix[i][j];
        }
    }
    initDist();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if(findPath({i, j})) {
                cnt++;
            } 
        }
    }
    cout << cnt << ' ';
    initDist();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if(findPathGR({i, j})) {
                cntGR++;
            } 
        }
    }
    cout << cntGR << '\n';
    return 0;
}