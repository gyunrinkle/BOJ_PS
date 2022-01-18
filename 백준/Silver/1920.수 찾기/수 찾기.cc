#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'

using namespace std;
using ll = long long;

const int MAX = 100'000;
int N, M;
vector<ll> A(MAX + 1);

bool BinarySearch(int target) {
    int s, e, mid;
    s = 1;
    e = N;
    while (s <= e) {
        mid = (s + e) / 2;

        if (target == A[mid]) {
            return true;
        }

        if (target > A[mid]) {
            s = mid + 1;
            continue;
        }

        if (target < A[mid]) {
            e = mid - 1;
            continue;
        }
    }

    return false;
}

void Input() {
    int t;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    sort(A.begin() + 1, A.begin() + 1 + N);
    cin >> M;
    for (int i = 1; i <= M; i++) {
        cin >> t;
        if (BinarySearch(t)) {
            cout << 1 << endl;
        }
        else {
            cout << 0 << endl;
        }
    }
}

void Solve() {
    Input();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    // freopen("input.txt", "r", stdin);
    Solve();
    return 0;
}