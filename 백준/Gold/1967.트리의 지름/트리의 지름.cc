#include <bits/stdc++.h>
#include <limits.h>
using namespace std;

const int MAX_VERTICES = 10000, MAX_WEIGHT = 100;
int n, next_start, diameter = INT_MIN;
vector<pair<int, int>> vertices[MAX_VERTICES + 1];
bool is_visited[MAX_VERTICES + 1] = {false,};

void Input() {
	int u, v, w;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		cin >> u >> v >> w;
		vertices[u].push_back({v, w});
		vertices[v].push_back({u, w});
	}
}

void InitIsVisited() {
	for (int i = 1; i <= n; i++) {
		is_visited[i] = false;
	}
}

void Backtracking(int vertex, int w_sum) {
	is_visited[vertex] = true;
	if (w_sum > diameter) {
		diameter = w_sum;
		next_start = vertex;
	}
	for (const auto& nv : vertices[vertex]) {
		if (is_visited[nv.first]) continue;
		Backtracking(nv.first, w_sum + nv.second);
		is_visited[nv.first] = false;
	}
}

void Solve() {
	Input();
	Backtracking(1, 0);
	InitIsVisited();
	Backtracking(next_start, 0);
	cout << diameter << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	Solve();
	return 0;
}
