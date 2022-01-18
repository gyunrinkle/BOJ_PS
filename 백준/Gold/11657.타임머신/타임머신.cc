#include <iostream>
#include <vector>
#include <tuple>
#define endl '\n'
#define pb push_back
using namespace std;
using ll = long long;

const int MAX_VERTICES = 500, MAX_EDGES = 6000, INF = (int)1e9;
int N, M;
vector<ll> dist(MAX_VERTICES + 1, INF);
vector<tuple<int, int, int>> edges;

void Input() {
    int A, B, C;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> A >> B >> C;
        edges.pb({A, B, C});
    }
}

bool BellmanFord(int start) {
    int src, dest, weight;
    dist[start] = 0;
    for (int i = 1; i <= N - 1; i++) {
        for (const auto& edge : edges) {
            tie(src, dest, weight) = edge;
            if (dist[src] == INF) continue;
            if (dist[dest] > dist[src] + weight) {
                dist[dest] = dist[src] + weight;
            }
        }
    }// N - 1 relaxation

    for (const auto& edge : edges) {
        tie(src, dest, weight) = edge;
        if (dist[src] == INF) continue;
        if (dist[dest] > dist[src] + weight) {
            return false;
        }
    } // 1번 도시에서 갈 수 있는 도시들 중에서, negative weight cycle이 있는지 확인하는 작업
    return true;
}

void Solve() {
    Input();
    if (BellmanFord(1) == false) {
        cout << -1 << endl;
    }
    else {
        for (int i = 2; i <= N; i++) {
            if (dist[i] == INF) {
                cout << -1 << endl;
            } 
            else {
                cout << dist[i] << endl;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    // freopen("input.txt", "r", stdin);
    Solve();
    return 0;
}