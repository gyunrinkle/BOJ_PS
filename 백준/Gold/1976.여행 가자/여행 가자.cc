#include <bits/stdc++.h>
#include <limits.h>
#define endl '\n'
#define pb push_back
using namespace std;

const int MAX = 200;
int N, M;
int root[MAX + 1] = {0,}, r_rank[MAX + 1] = {0,};
vector<int> cities;

void InitRoot() {
	for (int i = 1; i <= N; i++) {
		root[i] = i;
	}
}

int FindRoot(int v) {
	if (root[v] == v) {
		return v;
	}
	return root[v] = FindRoot(root[v]);
}

void Union(int u, int v) { // u가 부모, v가 자식
	u = FindRoot(u);
	v = FindRoot(v);
	if (r_rank[u] == r_rank[v]) {
		root[v] = u;
		r_rank[u]++;
		return;
	}
	if (r_rank[v] > r_rank[u]) swap(u, v);
	root[v] = u;
}

void Input() {
	int e;
    cin >> N;
	cin >> M;
	InitRoot();
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> e;
			if (e == 1) {
				Union(i, j);
			}
		}
	}
	for (int i = 0; i < M; i++) {
		cin >> e;
		cities.pb(e);
	}
}

void Solve() {
	int root_city;
    Input();
	root_city = FindRoot(cities[0]);
	for (const auto& c : cities) {
		if (root_city != FindRoot(c)) {
			cout << "NO" << endl;
			return;
		}
	}
	cout << "YES" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    Solve();
    return 0;
}