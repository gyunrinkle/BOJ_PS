#include <bits/stdc++.h>
#include <limits.h>
#define endl '\n'

using namespace std;
const int MAX_LEN = 1000;
string X, Y;
int max_dp;
int dp[MAX_LEN][MAX_LEN];
vector<vector<pair<int, int>>> idx(MAX_LEN, vector<pair<int, int>>(MAX_LEN));
stack<pair<int, int>> s;

void Input() {
	cin >> X;
	cin >> Y;
}

void BottomUp() {
	for (int i = 0; i < Y.length(); i++) {
		for (int j = 0; j < X.length(); j++) {
            if (Y[i] == X[j]) {
                // dp[i][j] = (i - 1 < 0 || j - 1 < 0 ? 0 : dp[i - 1][j - 1]) + 1;
                // idx[i][j] = i - 1 < 0 || j - 1 < 0 ? make_pair(-1, -1) : make_pair(i - 1, j - 1);
				if (i - 1 < 0 || j - 1 < 0) {
					dp[i][j] = 1;
					idx[i][j] = {i, j};
				}
				else {
					dp[i][j] = dp[i - 1][j - 1] + 1;
					idx[i][j] = {i - 1, j - 1};
				}
            }
            else {
                // dp[i][j] = max(i - 1 < 0 ? 0 : dp[i - 1][j], j - 1 < 0 ? 0 : dp[i][j - 1]);
				max_dp = INT_MIN;
				if (i - 1 < 0) {
					if (0 > max_dp) {
						max_dp = 0;
						idx[i][j] = {i, j};
					} 
				}
				else {
					if (dp[i - 1][j] > max_dp) {
						max_dp = dp[i - 1][j];
						idx[i][j] = {i - 1, j};
					} 
				}

				if (j - 1 < 0) {
					if (0 > max_dp) {
						max_dp = 0;
						idx[i][j] = {i, j};
					} 
				}
				else {
					if (dp[i][j - 1] > max_dp) {
						max_dp = dp[i][j - 1];
						idx[i][j] = {i, j - 1};
					} 
				}
				dp[i][j] = max_dp;
            }
		}
	}
}

void Solve() {
	pair<int, int> cur;
	Input();
	BottomUp();
	// for (int i = 0; i < Y.length(); i++) {
	// 	for (int j = 0; j < X.length(); j++) {
	// 		cout << dp[i][j] << ' ';
	// 	}cout << endl;
	// }

	// for (int i = 0; i < Y.length(); i++) {
	// 	for (int j = 0; j < X.length(); j++) {
	// 		cout << '(' << idx[i][j].first << ", " << idx[i][j].second << ") ";
	// 	}cout << endl;
	// }
	cout << dp[Y.length() - 1][X.length() - 1] << endl;
	if (dp[Y.length() - 1][X.length() - 1]) {
		cur = {Y.length() - 1, X.length() - 1};
		while (true) {
			s.push(cur);
			if (cur == idx[cur.first][cur.second]) break;
			cur = idx[cur.first][cur.second];
		}
		
		while (!s.empty()) {
			if (Y[s.top().first] == X[s.top().second]) cout << X[s.top().second];
			s.pop();
		}
		cout << endl;
	}
	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	Solve();
	return 0;
}