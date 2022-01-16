#include <bits/stdc++.h>
#include <limits.h>
#define endl '\n'
using namespace std;

const int MAX = 20, INF = INT_MAX;
int N;
int table[MAX][MAX] = {0,}, dp[(1 << MAX)];

void Input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> table[i][j];
        }
    }
}

int CountSetBits(int n) {
    int cnt = 0;
    while(n) {
        if (n & 1) {
            cnt++;
        }
        n = (n >> 1);
    }
    return cnt;
}

void Solve() {
    Input();
    for (int i = 0; i < (1 << N); i++) {
        dp[i] = INF;
    }
    dp[0] = 0;
    for (int mask = 0; mask < (1 << N); mask++) { 
        int k = CountSetBits(mask);
        for (int i = 0; i < N; i++) {
            if (~((1 << i) & mask)) {
                dp[mask | (1 << i)] = min(dp[mask | (1 << i)], dp[mask] + table[k][i]);
            }
        }
    }
    cout << dp[(1 << N) - 1] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    Solve();
    return 0;
}