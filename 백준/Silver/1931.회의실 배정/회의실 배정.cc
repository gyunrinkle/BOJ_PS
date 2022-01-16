#include <bits/stdc++.h>
#include <limits.h>
#define pb push_back
#define endl '\n'

using namespace std;

const int MAX = 100000;
int N, ans = 0;
vector<pair<int, int>> v;

bool criteria(const pair<int, int>& a, const pair<int, int>& b) {
	return a.second == b.second ? a.first < b.first : a.second < b.second;	
}

void Input() {
	int start, end;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> start >> end;
		v.pb({start, end});
	}
}

void Solve() {
	int prev_end_time;
	Input();
	sort(v.begin(), v.end(), criteria);
	prev_end_time = 0;
	for (const auto& p : v) {
		if (p.first >= prev_end_time) {
			prev_end_time = p.second;
			ans++;
			continue;
		}
	}
	cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	Solve();
	return 0;
}

// 첫째 줄에 회의의 수 N(1 ≤ N ≤ 100,000)이 주어진다. 
// 둘째 줄부터 N+1 줄까지 각 회의의 정보가 주어지는데 이것은 공백을 사이에 두고 회의의 시작시간과 끝나는 시간이 주어진다. 
// 시작 시간과 끝나는 시간은 2^31-1보다 작거나 같은 자연수 또는 0이다.