#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;

const int MAX = 500'000;
int N, M;
int cards[MAX], targets[MAX];

void Input() {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> cards[i];
    cin >> M;
    for (int i = 0; i < M; i++) cin >> targets[i];
}

int lower(int t) {
    int s, e, m;
    s = 0;
    e = N; // t이 모든 수가 큰 경우 N + 1을 반환해야 함 그래서 끝 idx를 N으로 설정
    while (s < e) {
        m = (s + e) / 2;
        if (t > cards[m]) s = m + 1;
        else e = m;
    }
    return s + 1;
} // t이상이 처음 나타나는 곳

int upper(int t) {
    int s, e, m;
    s = 0;
    e = N;
    while (s < e) {
        m = (s + e) / 2;
        if (t >= cards[m]) s = m + 1;
        else e = m;
    }
    return s + 1;
} // t초과가 처음 나타나는 곳

void Solve() {
    sort(&cards[0], &cards[0] + N);
    for (int i = 0; i < M; i++) {
        cout << upper(targets[i]) - lower(targets[i]) << ' ';
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