#include <bits/stdc++.h>
#include <limits.h>

using namespace std;
using ll = long long;
const int MAX_CITIES = 100, MAX_WEIGHT = 100000, INF = INT_MAX;
int n, m;
ll dist[MAX_CITIES + 1][MAX_CITIES + 1];

void InitDist() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dist[i][j] = i == j ? 0 : INF;
        }
    }
}

void Input() {
    int u, v, e;
    cin >> n;
    cin >> m;
    InitDist();
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> e;
        dist[u][v] = dist[u][v] > e ? e : dist[u][v]; // u -> v, e weight
    }
}

void FloydWarshall() { // DP의 일종
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

void Solve() {
    Input();
    FloydWarshall();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dist[i][j] == INF ? cout << 0 << ' ' : cout << dist[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    Solve();
    return 0;
}