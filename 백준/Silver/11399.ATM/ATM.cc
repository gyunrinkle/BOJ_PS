#include <bits/stdc++.h>
#include <limits.h>
#define pb push_back
#define endl '\n'

using namespace std;
const int MAX = 1000;
int N;
vector<int> P;
int sum_arr[MAX] = {0,};
int ans = 0;
void Input() {
    int p;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> p;
        P.pb(p);
    }
}

void Solve() {
    Input();
    sort(P.begin(), P.end());
    for (int i = 0; i < N; i++) {
        if (i == 0) {
            sum_arr[i] = P[i];
        }
        else {
            sum_arr[i] = P[i] + sum_arr[i - 1];
        }
        ans += sum_arr[i];
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    Solve();
    return 0;
}
// 첫째 줄에 사람의 수 N(1 ≤ N ≤ 1,000)이 주어진다. 둘째 줄에는 각 사람이 돈을 인출하는데 걸리는 시간 Pi가 주어진다. (1 ≤ Pi ≤ 1,000)