#include <bits/stdc++.h>
#include <limits.h>
#define pb push_back
#define endl '\n'

using namespace std;

struct cmp {
    bool operator() (pair<int, int>& a, pair<int, int>& b) {
        return a.second == b.second ?  a.first > b.first : a.second > b.second;
    }
};

const int MAX_VERTICES = 2000, INF = INT_MAX;
int T, n, m, t, s, g, h; //테스트 케이스, (노드, 간선, 목적지 후보의 개수,) (출발지, 경유 노드 1, 경유 노드 2)
int dist_s[MAX_VERTICES + 1] = {INF,}, dist_g[MAX_VERTICES + 1] = {INF,}, dist_h[MAX_VERTICES + 1] = {INF,}; // 무한대로 초기화
vector<pair<int, int>> vertices[MAX_VERTICES + 1];
vector<int> promising_ends; // 목적지 후보
priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

void InitPromisingEnds() {
    while (!promising_ends.empty()) promising_ends.pop_back();
	promising_ends.shrink_to_fit();
}
void InitVertices() {
    for (int i = 0; i < MAX_VERTICES + 1; i++) {
        while (!vertices[i].empty()) vertices[i].pop_back();
        vertices[i].shrink_to_fit();
    }
}

void InitDist(int (&dist)[MAX_VERTICES + 1]) {
    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
    }
}

void InitPriorityQueue() {
    while (!pq.empty()) pq.pop();
}

void Input() {
    int a, b, d, e;
    cin >> n >> m >> t;
    cin >> s >> g >> h;
    for (int i = 0; i < m; i++) { // 간선 정보 입력받기
        cin >> a >> b >> d;
        vertices[a].pb({b, d});
        vertices[b].pb({a, d});
    }

    for (int i = 0; i < t; i++) {
        cin >> e;
        promising_ends.pb(e);
    }
    sort(promising_ends.begin(), promising_ends.end());
}

void Dijkstra(int start, int (&dist)[MAX_VERTICES + 1]) {
    int cv, cdist, nv, ndist;// 현재 노드, 현재 우선순위큐에서 뺀 distance, 다음 노드, 다음 ""

    InitDist(dist);//dist 배열 INF로 초기화
    InitPriorityQueue();//우선순위큐 비우기

	dist[start] = 0;
    pq.push({start, 0});
    while (!pq.empty()) {
        tie(cv, cdist) = pq.top();
        pq.pop();
        if (cdist > dist[cv]) continue;
        for (const auto& v : vertices[cv]) {
            nv = v.first;
            ndist = v.second + cdist;
            if (ndist < dist[nv]){
				dist[nv] = ndist;
				pq.push({nv, ndist});
			} 
        }
    }
}

void Solve() {
    cin >> T;
    for (int i = 0; i < T; i++) {
        InitVertices();
        InitPromisingEnds();
        Input();
        Dijkstra(s, dist_s);
        Dijkstra(g, dist_g);
        Dijkstra(h, dist_h);
        for (const auto& e : promising_ends) {
            if (min(dist_s[g] + dist_g[h] + dist_h[e], dist_s[h] + dist_h[g] + dist_g[e]) == dist_s[e]) {
                cout << e << ' ';
            }
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
