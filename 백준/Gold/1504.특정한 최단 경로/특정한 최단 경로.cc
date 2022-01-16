#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAX = 800;
const ll INF = 200000 * 1000;

int N, E, v1, v2, res = 3 * INF;
vector<pair<int, int>> vertex[MAX + 1];
ll dist[MAX + 1];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void Input() {
	int a, b, c;
	cin >> N >> E;
	for (int i = 0; i < E; i++) {
		cin >> a >> b >> c; // a - b 사이 c의 가중치
		vertex[a].push_back({b, c});
		vertex[b].push_back({a, c});
	}
	cin >> v1 >> v2;
}

void InitPriorityQueue() {
	while(!pq.empty()) pq.pop();
}

void Dijkstra(int start) {
	fill_n(dist, MAX + 1, INF); // dist 배열 초기화
	InitPriorityQueue(); //우선순위 큐 초기화
	dist[start] = 0;
	pq.push({0, start});
	while (!pq.empty()) {
		int cdist, cv, nv, ndist;
		cdist = pq.top().first;
		cv = pq.top().second;
		pq.pop();
		if (cdist > dist[cv]) continue; // 우선순위 큐에 있는 게 dist 배열에 저장된 값보다 크다면 continue
		for (const auto& n : vertex[cv]) {
			ndist = cdist + n.second;
			nv = n.first;
			if (ndist < dist[nv]) {
				dist[nv] = ndist;
				pq.push({ndist, nv});
			}
		}
	}
}

void Solve() {
	Input();
	Dijkstra(1);
	if (dist[v1] == INF || dist[v2] == INF || dist[N] == INF) {
		res = -1;
	}
	else {
		int tmp = 0;
		if (v1 != 1) {
			tmp += dist[v1];
			Dijkstra(v1);
		} 
		if (v2 != N) {
			tmp += dist[v2];
			Dijkstra(v2);
		}
		tmp += dist[N];
		res = tmp < res ? tmp : res;
		
		Dijkstra(1);
		tmp = 0;
		if (v2 != 1) {
			tmp += dist[v2];
			Dijkstra(v2);
		} 
		if (v1 != N) {
			tmp += dist[v1];
			Dijkstra(v1);
		}
		tmp += dist[N];
		res = tmp < res ? tmp : res;
	}
	cout << res << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	Solve();
	return 0;
}