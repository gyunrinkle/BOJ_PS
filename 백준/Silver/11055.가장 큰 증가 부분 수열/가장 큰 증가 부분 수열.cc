#include <bits/stdc++.h>
#include <limits.h>

using namespace std;

const int MAX_LEN = 1000;
int N;
int A[MAX_LEN + 1], dp[MAX_LEN + 1];
int max_dp = INT_MIN;

void Input() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
}

void InitDP() {
    for (int i = 1; i <= N; i++) {
        dp[i] = 0;
    }
}
void BottomUp() {
    InitDP();
    dp[1] = A[1];
    for (int i = 2; i <= N; i++) {
        for (int j = 1; j < i; j++) {
            if (A[j] >= A[i]) continue;
            dp[i] = dp[j] > dp[i] ? dp[j] : dp[i];
        }
        dp[i] += A[i];
    }
}

void Solve() {
    Input();
    BottomUp();
    for (int i = 1; i <= N; i++) {
        if (dp[i] > max_dp) max_dp = dp[i];
    }
    cout << max_dp << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    Solve();
    return 0;
}