#include <bits/stdc++.h>
#include <limits.h>
using namespace std;

const int INF = INT_MAX;
const int MAX_VERTICES = 500, MAX_EDGES = 2500, MAX_NEGATIVE_EDGES = 200;
int TC, N, M, W;
int dist[MAX_VERTICES + 1];
vector<tuple<int, int, int>> edges; // src, dest, weight

void Input() {
    int S, E, T;
    cin >> N >> M >> W;
    for (int i = 0; i < M; i++) {
        cin >> S >> E >> T;
        edges.push_back({S, E, T});
        edges.push_back({E, S, T});
    }
    for (int i = 0; i < W; i++) {
        cin >> S >> E >> T;
        edges.push_back({S, E, -T});
    }
}

void InitDist() {
    for (int i = 1; i <= N; i++) {
        dist[i] = 1000000;
    }
}

bool BellmanFord(int start) {
    int src, dest, weight;

    InitDist();
    dist[start] = 0;
    for (int i = 1; i <= N - 1; i++) {
        for (const auto& edge : edges) {
            tie(src, dest, weight) = edge;
            // if (dist[src] == INF) continue; // 최소 한번은 relax된 src에서 계산을 해야 한다.
            if (dist[dest] > dist[src] + weight) {
                dist[dest] = dist[src] + weight;
            }
        }
    }// N - 1회 실행

    for (const auto& edge : edges) {
        tie(src, dest, weight) = edge;
        // if (dist[src] == INF) continue; // 최소 한번은 relax된 src에서 계산을 해야 한다.
        if (dist[dest] > dist[src] + weight) {
            return true;
        }
    }
    return false;
}

void Solve() {
    cin >> TC;
    for (int i = 0; i < TC; i++) {
        Input();
        if (BellmanFord(1)) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
        while(!edges.empty()) edges.pop_back();
    }
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    Solve();
    return 0;
}