#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;

const int MAX = 100000;
int n, x;
int a[MAX];

void Input() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    cin >> x;
}

void Solve() {
    int s, e, summation, cnt = 0;
    s = 0;
    e = n - 1;
    sort(&a[0], &a[0] + n);
    while (s < e) {
        summation = a[s] + a[e];
        if (summation == x) {
            cnt++;
            s++;
            e--;
            continue;
        }

        if (summation < x) {
            s++;
            continue;
        }

        if (summation > x) {
            e--;
            continue;
        }
    }
    cout << cnt << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    // freopen("input.txt", "r", stdin);
    Input();
    Solve();
    return 0;
}