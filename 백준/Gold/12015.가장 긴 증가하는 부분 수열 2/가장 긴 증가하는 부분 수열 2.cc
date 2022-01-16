#include <bits/stdc++.h>
#include <limits.h>
#define endl '\n'

using namespace std;

const int MAX_LEN = 1000000;//백만
int N, ans = 0;
int A[MAX_LEN + 1];
vector<int> LIS;

void Input() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
}

int BinarySearch(vector<int>& lis, int len, int target) {
    int s, e, mid, ret;
    s = 0;
    e = len - 1;
    while (s <= e) {
        mid = (s + e) / 2;
        if (lis[mid] == target) {
            return mid;
        }
        else {
            if (target < lis[mid]) {
                e = mid - 1;
            }
            else {
                s = mid + 1;
            }
        }
    }

    return s;
}

void Solve() {
    Input();
    for (int i = 1; i <= N; i++) {
        if (i == 1) {
            LIS.push_back(A[i]);
            ans++;
            continue;
        }
        if (LIS.back() < A[i]) {
            LIS.push_back(A[i]);
            ans++;
            continue;
        }
        LIS[BinarySearch(LIS, LIS.size(), A[i])] = A[i];
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    Solve();
    return 0;
}

// 첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000,000)이 주어진다.
// 둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (1 ≤ Ai ≤ 1,000,000)
// nlogn