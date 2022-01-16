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
vector<ll> LIS;

void Input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}
}

int BinarySearch(vector<ll>& lis, int len, ll target) {
	int s, e, mid;
	s = 1;
	e = len;
	
	while (s <= e) {
		mid = (e + s) / 2;
		
		if (lis[mid] == target) {
			return mid;
		}
		if (lis[mid] > target) {
			e = mid - 1;
			continue;
		}
		if (lis[mid] < target) {
			s = mid + 1;
			continue;
		}
	}
	return s;
}

void Solve() {
	Input();
	LIS.pb(NEGATIVE_INF); // LIS[0]
	for (int i = 1; i <= N; i++) { // O(N)
		if (LIS.back() < A[i]) {
			LIS.pb(A[i]);
			ans++;
			continue;
		}
		LIS[BinarySearch(LIS, LIS.size(), A[i])] = A[i]; // lower_bound와 동일한 작업 수행 O(logN)
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
// 둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (-1,000,000,000 ≤ Ai ≤ 1,000,000,000)
