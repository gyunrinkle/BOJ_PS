#include <iostream>
#include <string>
#include <algorithm>

#define endl '\n'

using namespace std;

const int MAX_LEN = 10;
char N[MAX_LEN + 1];

void Input() {
    fill_n(&N[0], MAX_LEN + 1, 0); // ASCII NUL
    cin >> N;
}

void Solve() {
    sort(&N[0], &N[0] + 10, greater<>());
    for (int i = 0; i < 10; i++) {
        if (N[i] == 0) break;
        cout << N[i];
    }cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    // freopen("input.txt", "r", stdin);
    Input();
    Solve();
    return 0;
}