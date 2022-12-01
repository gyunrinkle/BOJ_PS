#include <stdio.h>
#include <stdlib.h>

typedef long long ll;
#define MAX_LEN (int)1e6

ll dp[MAX_LEN + 1], V;

void get_input() {
    scanf("%ld", &V);
}

int solve() {
    for (int i = 1; i <= MAX_LEN; i++) {
        if (dp[i] > V) return i - 1;
    }
}

int main() {
    int T;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= MAX_LEN; i++) {
        dp[i] = dp[i - 1] + dp[i - 2] + 1;
    }

    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        get_input();
        printf("%d\n", solve());
    }

    return 0;
}
