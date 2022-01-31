#include <iostream>
#include <algorithm>
#define endl '\n'

using namespace std;
using ll = long long;
const int MAX = 1'000'000;
int N, M, ans = -1;
int a[MAX];
void Input() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) cin >> a[i];
}

bool IsValid(int mid) {
    ll summation = 0;
    for (int i = 0; i < N; i++) {
        if (mid > a[i]) continue;
        summation += a[i] - mid;
    }

    if (summation >= M) {
        if (mid > ans) ans = mid;
        return true;
    }

    return false;
}

void Solve() {
    int s, e, m;
    sort(&a[0], &a[0] + N);
    s = 0;
    e = a[N - 1];
    while (s <= e) {
        m = (s + e) / 2;
        if (IsValid(m)) {
            s = m + 1;
            continue;
        }
        e = m - 1;
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    // freopen("input.txt", "r", stdin);
    Input();
    Solve();
    return 0;
}