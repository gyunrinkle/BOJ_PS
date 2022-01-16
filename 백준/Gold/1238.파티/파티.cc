#include <bits/stdc++.h>
using namespace std;

const int INF = 100 * 10000;
const int MAX = 1000;
int N, M, X;
int dist_depart[MAX + 1][MAX + 1];
int dist_comeback[MAX + 1];
vector<pair<int, int>> vertex[MAX + 1];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void Input() {
    cin >> N >> M >> X;
    for (int i = 0; i < M; i++) {
        int A, B, T;
        cin >> A >> B >> T;
        vertex[A].push_back({B, T}); // A -> B로 가는 데에 T시간 걸린다.
    }
    // for (int i = 1; i <= N; i++) {
    //     for (const auto& j : vertex[i]) {
    //         cout << j.first << ' ' << j.second << '\n';
    //     }
    // }
}

void ClearPriorityQueue() {
    while (!pq.empty()) pq.pop();
}
void Dijkstra(int start, int (&dist)[MAX + 1]) {
    pq.push({dist[start], start});
    while (!pq.empty()) {
        int cur_vertex, cur_dist_pq;
        cur_dist_pq = pq.top().first;
        cur_vertex = pq.top().second;
        pq.pop();
        if (cur_dist_pq > dist[cur_vertex]) continue;
        for (const auto& e : vertex[cur_vertex]) {
            int nv = e.first;
            int nv_dist = cur_dist_pq + e.second;
            if (nv_dist < dist[nv]) {
                dist[nv] = nv_dist;
                pq.push({nv_dist, nv});
            }
        }
    }
    // cout << start << " 의 다익스트라 결과:\n";
    // for (int i = 1; i <= N; i++) {
    //     cout << dist[i] << ' ';
    // }
    // cout << "\n--------------\n";
}

void Depart() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i == j){
                dist_depart[i][j] = 0;
                continue;
            } 
            dist_depart[i][j] = INF;
        }
    }
    for (int i = 1; i <= N; i++) {
        ClearPriorityQueue();
        Dijkstra(i, dist_depart[i]);
    }
}

void ComeBack() {
    for (int i = 1; i <= N; i++) {
        if (i == X){
            dist_comeback[i] = 0;
            continue;
        } 
        dist_comeback[i] = INF;
    }
    ClearPriorityQueue();
    Dijkstra(X, dist_comeback);
}

void Solve() {
    int sum, max_sum = -1;
    Input();
    Depart();
    ComeBack();
    for (int i = 1; i <= N; i++) {
        sum = dist_depart[i][X] + dist_comeback[i];
        // cout << dist_depart[i][X] << ' ' << dist_comeback[i] << "= " << sum << '\n';
        if (max_sum < sum) max_sum = sum;
    }
    cout << max_sum << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    Solve();
    return 0;
}