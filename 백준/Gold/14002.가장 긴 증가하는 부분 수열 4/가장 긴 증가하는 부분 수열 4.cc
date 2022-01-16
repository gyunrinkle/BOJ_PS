#include <bits/stdc++.h>
#include <limits.h>
#define endl '\n'

using namespace std;

const int MAX_LEN = 1000;
int N, max_dp = INT_MIN, max_dp_idx;
int A[MAX_LEN + 1], dp[MAX_LEN + 1] = {0,}, dp_index[MAX_LEN + 1] = {0,};
stack<int> s;

void Input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}
}

void BottomUp() {
	dp[1] = 1;
	for (int i = 2; i <= N; i++) {
		for (int j = 1; j < i; j++) {
			if (A[j] >= A[i]) continue;
			if (dp[j] > dp[i]) {
				dp[i] = dp[j];
				dp_index[i] = j;
				continue;
			}
		}
		dp[i] += 1;
	}
}

void Solve() {
	int cur;
	Input();
	BottomUp();
	for (int i = 1; i <= N; i++) {
		if (dp[i] > max_dp) {
			max_dp = dp[i];
			max_dp_idx = i;
		}
	}
	cur = max_dp_idx;
	while (cur != 0) {
		s.push(A[cur]);
		cur = dp_index[cur];
	}
	cout << max_dp << endl;
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

// 첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000)이 주어진다.
// 둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (1 ≤ Ai ≤ 1,000)