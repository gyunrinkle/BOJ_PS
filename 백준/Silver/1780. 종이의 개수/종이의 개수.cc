#include <iostream>
#define endl '\n'

using namespace std;

const int MAX = 2187;
//첫째 줄에 N(1 ≤ N ≤ 3^7, N은 3^k 꼴)이 주어진다. 다음 N개의 줄에는 N개의 정수로 행렬이 주어진다.
int N;
// 16MB정도
int MATRIX[MAX][MAX];
int ans1, ans2, ans3;
// size는 3의 지수 k를 나타냄
int get_pow(int num) {
    int ret = 1;
    for (int i = 0; i < num; i++) {
        ret *= 3;
    }
    return ret;
}

int recursion(int size, int si, int sj, int delimeter) {
    if (size == 0) {
        if (MATRIX[si][sj] == delimeter)
            return 1;
        else return 0;
    }
    int i_range = get_pow(size);
    int j_range = i_range;
    int prev = MATRIX[si][sj];
    bool is_same = true;
    for (int i = si; i < si + i_range; i++) {
        for (int j = sj; j < sj + j_range; j++) {
            if (i == si && j == sj) {
                continue;
            }

            if (prev != MATRIX[i][j]) {
                is_same = false;
                break;
            }
            prev = MATRIX[i][j];
        }
    }
    if (is_same) {
        if (MATRIX[si][sj] == delimeter) 
            return 1;
        else return 0;
    }
    int delta = get_pow(size-1);
    int summation = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            summation += recursion(size - 1, si + delta * i, sj + delta * j, delimeter);
        }
    }
    return summation;
}
void solve() {
    int s = 0;
    while (N > 1) {
        N /= 3;
        s++;
    }
    // cout << s << endl;
    cout << recursion(s, 0, 0, -1) << endl;
    cout << recursion(s, 0, 0, 0) << endl;
    cout << recursion(s, 0, 0, 1) << endl;
}

void read_user_input() {
    cin >> N; 
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> MATRIX[i][j];
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    read_user_input();    
    solve();
    return 0;
}
