#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#define MAX_LEN 4 * (int)1e6

int N;
bool isPrime[MAX_LEN + 1];
int seq[MAX_LEN];

void calcPrimes() {
    int sqrtN = sqrt(N);

    for (int i = 1; i <= N; i++) isPrime[i] = true; //창문을 다 연다.

    isPrime[1] = false; //닫는다
    isPrime[2] = true; //냅둔다

    for (int i = 2; i <= (int)(N / 2); i++) {
        isPrime[2 * i] = false; //2의 배수는 닫는다
    }

    for (int i = 3; i <= sqrtN; i += 2) {
        if (isPrime[i]) { //창문이 열려 있으면
            for (int j = i * i; j <= N; j += i) isPrime[j] = false; // 그 창문의 배수는 창문을 닫는다
        }
    }
}
int solve() {
    int top = -1, sum, s, e, cnt = 0;
    calcPrimes();
    for (int i = 1; i <= N; i++) {
        if (isPrime[i]) seq[++top] = i; //스택처럼
    }
    s = 0;
    e = 0;
    sum = seq[0];
    while (s <= e && e < top + 1) {
        if (sum == N) {
            cnt++;
            sum -= seq[s];
            s++;
            continue;
        }
        if (sum > N) {
            sum -= seq[s];
            s++;
            continue;
        }
        if (sum < N) {
            e++;
            sum += seq[e];
            continue;
        }
    }
    return cnt;
}

void getInput() {
    scanf("%d", &N);
}

int main() {
    getInput();
    printf("%d\n", solve());
    return 0;
}
