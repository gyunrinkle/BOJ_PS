#include <bits/stdc++.h>
#include <limits.h>
#define endl '\n'

using namespace std;

const int MAX = 1000000;
int N, min_dp, min_idx;
int dp[MAX + 1], idx[MAX + 1];

void Input() {
	cin >> N;	
}

void BottomUp() {
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;
	
	idx[1] = 0;
	idx[2] = 1;
	idx[3] = 1;
	
	for (int i = 4; i <= N; i++) {
		min_dp = MAX + 1;
		if (i % 3 == 0) {
			if (dp[i / 3] < min_dp) {
				min_dp = dp[i / 3];
				min_idx = i / 3;
			} 
		}
		if (i % 2 == 0) {
			if (dp[i / 2] < min_dp) {
				min_dp = dp[i / 2];
				min_idx = i / 2;
			} 
		}
		if (i > 1) {
			if (dp[i - 1] < min_dp) {
				min_dp = dp[i - 1];
				min_idx = i - 1;
			} 
		}
		
		dp[i] = min_dp + 1;
		idx[i] = min_idx;
	}
	
}

void Solve() {
	int cur;
	Input();
	BottomUp();
	cout << dp[N] << endl;
	cur = N;
	while (cur != 0) {
		cout << cur << ' ';
		cur = idx[cur];
	}
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	Solve();
	return 0;
}