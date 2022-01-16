#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MAX = 100000;
int N, M;
int S[MAX + 1] = {0,};
void Input() {
    int e, a, b, summation = 0;
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> e;
        summation += e;
        S[i] = summation;
    }
    for (int i = 1; i <= M; i++) {
        cin >> a >> b;
        cout << S[b] - S[a - 1] << endl;
    }
}

void Solve() {
    Input();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    Solve();
    return 0;
}