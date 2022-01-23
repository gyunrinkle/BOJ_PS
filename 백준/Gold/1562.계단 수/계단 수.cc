#include <iostream>
#include <cstring>
#define endl '\n'
using namespace std;
using ll = long long;
const int MAX = 100, MOD = 1'000'000'000;
int N;
ll dp[(1 << 10)][MAX + 1][10];

void Input() {
    cin >> N;
}

ll BackTracking(int mask, int len, int last_digit) {
    if (len == N) {
        if (mask == (1 << 10) - 1) {
            return 1;
        }
        return 0;
    }
    if (len == 1 && last_digit == 0) return 0;
    ll& ret = dp[mask][len][last_digit];
    if (ret != -1) return ret;
    if (ret == -1) ret = 0;
    for (int i = 0; i < 10; i++) {
        if (len == 0) {
            ret += BackTracking(mask | (1 << i), len + 1, i) % MOD;
        }
        else {
            if (abs(last_digit - i) != 1) continue;
            ret += BackTracking(mask | (1 << i), len + 1, i) % MOD;
        }
    }

    return ret = ret % MOD;
}

void Solve() {
    memset(&dp[0][0][0], -1, sizeof(dp));
    cout << BackTracking(0, 0, 0) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    // freopen("input.txt", "r", stdin);
    Input();
    Solve();
    return 0;
}