#include <bits/stdc++.h>
using namespace std;

const int MAX_LEN = 500;
const int MIN = 4;
int N, M;
int matrix[MAX_LEN][MAX_LEN];
bool is_visited[MAX_LEN][MAX_LEN];
int max_sum = MIN;
vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
vector<pair<int,int>> shape[4] = {
        {{0, 0}, {-1, 0}, {0, -1}, {0, 1}},//up
        {{0, 0}, {1, 0}, {0, -1}, {0, 1}},//down
        {{0, 0}, {0, -1}, {1, 0}, {-1, 0}},//left
        {{0, 0}, {0, 1}, {1, 0}, {-1, 0}}//right
};

void Input() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> matrix[i][j];
        }
    }
}
void InitIsVisited() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            is_visited[i][j] = false;
        }
    }
}
bool IsPromisingPos(int i, int j) {
    if (i < 0 || i >= N) return false;
    if (j < 0 || j >= M) return false;
    return true;
}
void DFS(int ci, int cj, int sum, int level) {
    if (is_visited[ci][cj] == true) return;
    is_visited[ci][cj] = true;
    if (level == 3) {
        if (sum > max_sum) max_sum = sum;
        return;
    }
    for (const auto& d : dir) {
        int ni, nj;
        tie(ni, nj) = make_pair(ci + d.first, cj + d.second);
        if (IsPromisingPos(ni, nj) == false) continue;
        if (is_visited[ni][nj] == true) continue;
        DFS(ni, nj, sum + matrix[ni][nj], level + 1);
        is_visited[ni][nj] = false;
    }
}
void TShapeTetromino(int ci, int cj) {
    int sum  = 0;
    bool b_promising_pos = true;
    for (const auto& type : shape) {
        b_promising_pos = true;
        sum = 0;
        for (const auto& coord: type) {
            int ni, nj;
            tie(ni, nj) = make_pair(ci + coord.first, cj + coord.second);
            if (IsPromisingPos(ni, nj) == false) {
                b_promising_pos = false;
                break;
            }
            sum += matrix[ni][nj];
        }
        if (b_promising_pos == false) continue;
        if (sum > max_sum) max_sum = sum;
    }
}
void solve() {
    Input();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            InitIsVisited();
            DFS(i, j, matrix[i][j], 0);
            TShapeTetromino(i, j);
        }
    }
    cout << max_sum << '\n';
    
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}