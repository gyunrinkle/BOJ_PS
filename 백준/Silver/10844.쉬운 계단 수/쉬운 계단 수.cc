#include <iostream>
#define endl '\n'

using namespace std;
using ll = long long;
const int MAX = 100;
const ll MOD = 1'000'000'000;
int N;
ll dp[MAX + 1][10];

void Input() {
    cin >> N;
}

void Solve() {
    ll ans = 0;
    Input();
    fill_n(&dp[0][0], sizeof(dp) / sizeof(ll), 0);
    for (int i = 0; i <= 9; i++) {
        if (i == 0) {
            dp[1][i] = 0;
        }
        else {
            dp[1][i] = 1;
        }
        
    }
    for (int i = 2; i <= N; i++) {
        for (int j = 0; j <= 9; j++) {
            if (j == 0) {
                dp[i][j] = dp[i - 1][j + 1] % MOD;
                continue;
            }
            if (j == 9) {
                dp[i][j] = dp[i - 1][j - 1] % MOD;
                continue;
            }
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % MOD;
        }
    }
    for(int i = 0; i <= 9; i++) {
        ans += dp[N][i];
    }
    cout << ans % MOD << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    // freopen("input.txt", "r", stdin);
    Solve();
    return 0;
}