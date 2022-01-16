#include <bits/stdc++.h>
using namespace std;
const int MAX_LEN = 50;
int R, C, T, ans = 0;
vector<pair<int, int>> purifier_pos;
int room[MAX_LEN][MAX_LEN], memo[MAX_LEN][MAX_LEN] = {0,};
vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void Input() {
    cin >> R >> C >> T;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> room[i][j];
            if (room[i][j] == -1) {
                purifier_pos.push_back({i, j});
            }
        }
    }

}

bool IsPromisingPos(int i, int j) {
    if (i < 0 || i >= R) return false;
    if (j < 0 || j >= C) return false;
    if (room[i][j] == -1) return false;
    return true;
}

void Diffuse() {
    int amount;
    for (int i  = 0; i < R; i++) {
        for (int j = 0; j < C; j ++) {
            if (room[i][j] == -1) continue;
            amount = room[i][j] / 5;
            for (const auto& d : dir) {
                int ni, nj;
                tie(ni, nj) = make_pair(i + d.first, j + d.second);
                if (IsPromisingPos(ni, nj) == false) continue;
                memo[ni][nj] += amount;
                room[i][j] -= amount;
            }            
        }
    }
}

void SumMemo() {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            room[i][j] += memo[i][j];
        }
    }
}

void ClockWise() {
    int origin_i, origin_j, cur_i, cur_j, ni, nj;
    pair<int, int> move_vector = {1, 0};
    bool iteration_trigger = true;
    tie(origin_i, origin_j) = purifier_pos[1];
    cur_i = origin_i, cur_j = origin_j;
    while (iteration_trigger) {
        if (cur_i == origin_i && cur_j == origin_j) { // 첫번째의 경우
            cur_i += move_vector.first;
            cur_j += move_vector.second;
            continue;
        }

        if (cur_i == origin_i && cur_j == origin_j + 1) { // 마지막의 경우
            room[cur_i][cur_j] = 0;
            iteration_trigger = false;
            continue;
        }

        ni = cur_i + move_vector.first;
        nj = cur_j + move_vector.second;
        if (ni == R) { // 방향을 바꿀 때 1
            ni = cur_i;
            nj = cur_j + 1;
            move_vector = {0, 1};
        }
        else if (nj == C) { // 방향을 바꿀 때 2
            ni = cur_i - 1;
            nj = cur_j;
            move_vector = {-1, 0};
        } 
        else if (ni < origin_i) { // 방향을 바꿀 때 3
            ni = cur_i;
            nj = cur_j - 1;
            move_vector = {0, -1};
        }
        room[cur_i][cur_j] = room[ni][nj];
        cur_i = ni, cur_j = nj;
    }
    
}

void AntiClockWise() {
    int origin_i, origin_j, cur_i, cur_j, ni, nj;
    pair<int, int> move_vector = {-1, 0};
    bool iteration_trigger = true;
    tie(origin_i, origin_j) = purifier_pos[0];
    cur_i = origin_i, cur_j = origin_j;
    while (iteration_trigger) {
        if (cur_i == origin_i && cur_j == origin_j) { // 첫번째의 경우
            cur_i += move_vector.first;
            cur_j += move_vector.second;
            continue;
        }

        if (cur_i == origin_i && cur_j == origin_j + 1) { // 마지막의 경우
            room[cur_i][cur_j] = 0;
            iteration_trigger = false;
            continue;
        }

        ni = cur_i + move_vector.first;
        nj = cur_j + move_vector.second;
        if (ni < 0) { // 방향을 바꿀 때 1
            ni = cur_i;
            nj = cur_j + 1;
            move_vector = {0, 1};
        }
        else if (nj == C) { // 방향을 바꿀 때 2
            ni = cur_i + 1;
            nj = cur_j;
            move_vector = {1, 0};
        } 
        else if (ni > origin_i) { // 방향을 바꿀 때 3
            ni = cur_i;
            nj = cur_j - 1;
            move_vector = {0, -1};
        }
        room[cur_i][cur_j] = room[ni][nj];
        cur_i = ni, cur_j = nj;
    }
}

void InitMemo() {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            memo[i][j] = 0;
        }
    }
}

void Solve() {
    Input();
    for (int i = 0; i < T; i++) {
        //확산 과정
        InitMemo();
        Diffuse();
        SumMemo();
        //순환 시키기
        ClockWise();
        AntiClockWise();
    }

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (room[i][j] == -1) continue;
            ans += room[i][j];
        }
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    Solve();
    return 0;
}