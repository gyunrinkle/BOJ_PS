#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define endl '\n'
#define pb push_back

using namespace std;

const int MAX = 1000;
int T, N, M;
vector<int> graph[MAX + 1];
vector<bool> IsVisited(MAX + 1, false);
queue<int> q;

void Input() {
	cin >> T;
}

int BFS(int start) {
	int cur, cnt = 0;
	q.push(start);
	while (!q.empty()) {
		cur = q.front();
		q.pop();
		if (IsVisited[cur] == true) continue;
		IsVisited[cur] = true;
		cnt++;
		for (const auto& nv : graph[cur]) {
			if (IsVisited[nv] == true) continue;
			q.push(nv);
		}
	}
	return cnt;
}

void Solve() {
	int a, b;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		graph[a].pb(b);
		graph[b].pb(a);
	}
	cout << BFS(1) - 1 << endl;
	
	for (int i = 1; i <= N; i++) {
		graph[i].clear();
		vector<int>().swap(graph[i]);
	}
	fill(IsVisited.begin(), IsVisited.end(), false);
	while(!q.empty()) q.pop();
	queue<int>().swap(q);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	// freopen("input.txt", "r", stdin);
	Input();
	while (T) {
		Solve();
		T--;
	}
	return 0;
}

