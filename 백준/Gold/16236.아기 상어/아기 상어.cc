#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

typedef struct shark {
    int pos_i, pos_j, size, eat;
}Shark;

const int MAX_LEN = 20;
int N, res = 0;
int dist[MAX_LEN][MAX_LEN];
int matrix[MAX_LEN][MAX_LEN];
int dir_i[4] = {-1, 1, 0, 0};
int dir_j[4] = {0, 0, -1, 1};

bool findPrey(Shark& babyShark) {
    
    queue<tuple<int, int, int>> q;
    int mi, mj, mDist = 400;//dist 최소값
    for(int i = 0; i < MAX_LEN; i++) { // dist 배열 초기화
        for(int j = 0; j < MAX_LEN; j++) {
            dist[i][j] = -1;
        }
    }
    q.push(make_tuple(babyShark.pos_i, babyShark.pos_j, dist[babyShark.pos_i][babyShark.pos_j] + 1));
    while (!q.empty()) {
        int cur_i, cur_j, cur_dist;
        tie(cur_i, cur_j, cur_dist) = q.front();
        q.pop();
        if (dist[cur_i][cur_j] == -1) {
            dist[cur_i][cur_j] = cur_dist;
            for (int k = 0; k < 4; k++) {
                int ni, nj;
                tie(ni, nj) = make_pair(cur_i + dir_i[k], cur_j + dir_j[k]);
                if (matrix[ni][nj] != 9 && matrix[ni][nj] != 0 && matrix[ni][nj] > babyShark.size) continue; //자기 보다 큰 물고기 좌표는 push하지 않음
                if (ni >= 0 && ni < N && nj >= 0 && nj < N && dist[ni][nj] == -1 && matrix[ni][nj] <= babyShark.size) {
                    q.push(make_tuple(ni, nj, cur_dist + 1));
                }
            }
        }
    }
    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < N; j++) {
    //         cout << dist[i][j] << ' ';
    //     }
    //     cout << '\n';
    // } 디버그 출력
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (matrix[i][j] < babyShark.size && dist[i][j] < mDist && dist[i][j] != -1 && matrix[i][j] != 0 && matrix[i][j] != 9) {
                mDist = dist[i][j];
                mi = i;
                mj = j;
            }
        }
    }
    if (mDist == 400) {
        return false;
    }
    else {
        matrix[babyShark.pos_i][babyShark.pos_j] = 0;
        babyShark.pos_i = mi;
        babyShark.pos_j = mj;
        babyShark.eat += 1;
        if (babyShark.eat == babyShark.size) {
            babyShark.size += 1;
            babyShark.eat = 0;
        }

        res += mDist;
        matrix[mi][mj] = 9;
        
        return true;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Shark s;
    bool bIterationTrigger = true;
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> matrix[i][j];
            if (matrix[i][j] == 9) {
                s.pos_i = i;
                s.pos_j = j;
                s.eat = 0;
                s.size = 2;
            }
        }
    }
    while (bIterationTrigger) {
        if (findPrey(s)) {
            continue;
        }
        else {
            bIterationTrigger = false;
            continue;
        }
    }
    cout << res << '\n';
    return 0;
}