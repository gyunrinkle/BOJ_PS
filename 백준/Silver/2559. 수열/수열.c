#include <stdio.h>

#define MAX_LEN (int)1e5

int N, K;
int temp[MAX_LEN];
int prefixSum[MAX_LEN];
int kPrefixSum[MAX_LEN];

void getInput() {
    scanf("%d%d", &N, &K);
    for(int i = 0; i < N; i++) scanf("%d", &temp[i]);
}

void Solve() {
    int top = -1, max = -1 * (int)1e9;
    prefixSum[0] = temp[0];
    for (int i = 1; i < N; i++) prefixSum[i] = prefixSum[i - 1] + temp[i];
    kPrefixSum[++top] = prefixSum[K - 1];
    for (int i = K; i  < N; i++) kPrefixSum[++top] = prefixSum[i] - prefixSum[i - K];
    for (int i = 0; i <= top; i++) {
        if (kPrefixSum[i] > max) max = kPrefixSum[i];
    }
    printf("%d\n", max);
}

int main() {
    getInput();
    Solve();
    return 0;
}
