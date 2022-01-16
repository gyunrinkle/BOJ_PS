#include <bits/stdc++.h>
#include <limits.h>
#define endl '\n'
using namespace std;
using ll = long long;
const int MAX = 16, INF = INT_MAX;
ll N, answer = INF;
ll W[MAX + 1][MAX + 1], dp[1 << (MAX + 1)][MAX + 1];


void Input() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> W[i][j];
        }
    }
}

int CountSetBits(int m) {
    int cnt = 0;
    while (m) {
        if (m & (1 << 1)) {
            cnt++;
        }
        m = m >> 1;
    }
    return cnt;
}

void Solve() {
    Input();
    for (int i = 0; i < (1 << (N + 1)); i++) {
        for (int j = 1; j <= N; j++) {
            dp[i][j] = INF;
        }
    }
    //항상 1번에서 출발
    // {1, i} -> i != 1 초기화
    for (int i = 2; i <= N; i++) {
        if (W[1][i] == 0) continue; // 해당 도시로 갈 수 없는 경우 업데이트 하지 않는다. 무한으로 남겨 놓는다.
        dp[(1 << 1) | (1 << i)][i] = W[1][i];
    }
    // {1, ..., i} n(S) > 2
    // dp(S(mask), i) =  min{ dp(S - {i}, j) + W[j][i]} i != j, j!= 1
    for (int mask = (1 << 1) | (1 << 2); mask < (1 << (N + 1)); mask++) {
        if (mask & (1 << 0)) continue; //0번 도시는 없다.
        if (CountSetBits(mask) < 2) continue;
        if (!(mask & (1 << 1))) continue; // S에는 항상 1이 있어야 한다.
        for (int i = 1; i <= N; i++) { 
            if (!((1 << i) & mask)) {
                for (int j = 2; j <= N; j++) { // j != 1
                    if (i != j && ((1 << j) & mask)) { // i != j, j는 S에 있어야 한다. 실수: 임의의 도시 - 임의의 도시 갈 수 없는 경우를 처리 해줘야 한다.
                        dp[mask | (1 << i)][i] = min(dp[mask | (1 << i)][i], W[j][i] == 0 ? dp[mask][j] + INF : dp[mask][j] + W[j][i]);
                    }
                }
            }
        }
    }

    for (int i = 2; i <= N; i++) {
        answer = min(answer, W[i][1] == 0 ? dp[(1 << (N + 1)) - 2][i] + INF : dp[(1 << (N + 1)) - 2][i] + W[i][1]);
    }
    cout << answer << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    Solve();
    return 0;
}