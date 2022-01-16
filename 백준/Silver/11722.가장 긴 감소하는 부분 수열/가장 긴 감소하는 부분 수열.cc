#include <bits/stdc++.h>
#include <limits.h>
#define endl '\n'
using namespace std;

const int MAX_LEN = 1000;
int N, max_dp = INT_MIN;
int A[MAX_LEN + 1], dp[MAX_LEN + 1] = {0,};

void Input() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
}

void BottomUp() {
    dp[1] = 1;
    for (int i = 2; i <= N; i++) {
        for (int j = 1; j < i; j++) {
            if (A[j] <= A[i]) continue;
            dp[i] = dp[j] > dp[i] ? dp[j] : dp[i];
        }
        dp[i] += 1;
    }
}

void Solve() {
    Input();
    BottomUp();
    for (int i = 1; i <= N; i++) {
        if (dp[i] > max_dp) max_dp = dp[i];
    }
    cout << max_dp << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    Solve();
    return 0;
}