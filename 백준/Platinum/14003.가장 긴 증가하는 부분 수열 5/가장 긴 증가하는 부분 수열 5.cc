#include <bits/stdc++.h>
#include <limits.h>

#define endl '\n'
#define pb push_back

using namespace std;
using ll = long long;

const int MAX_LEN = 1000000;
const ll NEGATIVE_INF = LLONG_MIN;
int N, ans = 0;
ll A[MAX_LEN + 1];
int idx[MAX_LEN + 1];
vector<ll> LIS;
stack<ll> s;

void Input() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
}

int BinarySearch(vector<ll>& v, int len, ll target) {
    int s, e, mid;
    s = 1;
    e = len - 1;
    while (s <= e) {
        mid = (s + e) / 2;
        if (v[mid] == target) {
            return mid;
        }
        if (target < v[mid]) {
            e = mid - 1;
            continue;
        }
        if (target > v[mid]) {
            s = mid + 1;
            continue;
        }
    }
    return s;

}
void Solve() {
    int upd, target_idx;
    Input();
    LIS.pb(NEGATIVE_INF);
    for (int i = 1; i <= N; i++) {
        if (A[i] > LIS.back()) {
            LIS.pb(A[i]);
            ans++;
            idx[i] = LIS.size() - 1;
            continue;
        }
        upd = BinarySearch(LIS, LIS.size(), A[i]); 
        LIS[upd] = A[i];
        idx[i] = upd;
    }
    cout << ans << endl;
    // for (const auto& e : LIS) {
    //     if (e == NEGATIVE_INF) continue;
    //     cout << e << ' ';
    // }//debug
    cout << endl;
    target_idx = LIS.size() - 1;
    for (int i = N; i > 0; i--) {
        if (idx[i] == target_idx) {
            s.push(A[i]);
            target_idx--;
        }
    }

    while (!s.empty()) {
        cout << s.top() << ' ';
        s.pop();
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    Solve();
    return 0;
}
// 첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000,000)이 주어진다.
// 둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (-1,000,000,000 ≤ Ai ≤ 1,000,000,000)