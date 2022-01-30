#include <iostream>
#include <algorithm>
#define endl '\n'

using namespace std;

const int MAX = 200'000;
int N, C, ans = -1;
int pos[MAX];
void Input() {
    cin >> N >> C;
    for (int i = 0; i < N; i++) cin >> pos[i];
}

bool IsMidValid(int mid) {
    int cur_pos = 0, cnt = 1;

    for(int i = 1; i < N; i++) {
        if (pos[i] - pos[cur_pos] >= mid) {
            cnt++;
            cur_pos = i;
        }
    }
    if (cnt >= C) {
        if (mid > ans) ans = mid;
        return true;
    }

    return false;
}

void BinarySearch() {
    int s, e, m;
    s = 0; //pos[0];
    e = pos[N - 1];
    while (s <= e) {
        m = (s + e) / 2;
        if (IsMidValid(m)) { // mid값을 더 키워서, ans가 더 큰값으로 검색될 가능성을 보여라
            s = m + 1;
            continue;
        }
        e = m - 1; // mid값이 커서, cnt가 C도 못 넘고 있으니, mid값을 낮춰라
    }
}

void Solve() {
    int dist;
    sort(&pos[0], &pos[0] + N);
    BinarySearch();
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