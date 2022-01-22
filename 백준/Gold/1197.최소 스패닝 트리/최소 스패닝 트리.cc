#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

#define endl '\n'
#define pb push_back

using namespace std;

const int MAX_VERTICES = 10'000, MAX_EDGES = 100'000;
int V, E;
vector<int> parents(MAX_VERTICES + 1), height(MAX_VERTICES + 1, 0);
vector<tuple<int, int, int>> edges;

void Input() {
	int A, B, C;
	cin >> V >> E;
	while (E) {
		cin >> A >> B >> C;
		edges.pb({C, A, B});
		E--;
	}
	sort(edges.begin(), edges.end());
}

void InitParents() {
	for (int i = 1; i <= V; i++) {
		parents[i] = i;
	}
}

int Find(int x) {
	if (parents[x] == x) return x;
	return parents[x] = Find(parents[x]);
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);
	
	if (x == y) {
		height[x]++;
		parents[y] = x;
		return;
	}
	
	if (height[y] > height[x]) swap(x, y);
	parents[y] = x;
}

void Solve() {
	int weight, u, v, MST = 0;
	InitParents();
	for (const auto& edge : edges) {
		tie(weight, u, v) = edge;
		if (Find(u) == Find(v)) continue;
		Union(u, v);
		MST += weight;
	}
	cout << MST << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	// freopen("input.txt", "r", stdin);
	Input();
	Solve();
	return 0;
}