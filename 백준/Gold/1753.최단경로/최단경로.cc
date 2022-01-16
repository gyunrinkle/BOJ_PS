#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define VERTEX_MAX 20001
#define EDGE_MAX 300001
#define INF 1000000000

int main() {
    int V, E, K; // vertex, edge, starting vertex
    int dist[VERTEX_MAX]; // starting vertex로 부터 다른 vertex까지의 최단 경로를 정리해 놓은 배열
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<pair<int, int>> vertex[VERTEX_MAX]; // vertex 사이의 관계를 나타낸 vector

    cin >> V >> E;
    cin >> K;
    
    for (int i = 0; i < E; i++) {
        int u, v, w;

        cin >> u >> v >> w;

        vertex[u].push_back({w, v}); //vertex u에 대해 가중치 w, 연결된 vertex v
    }

    dist[K] = 0;

    for (int i = 1; i <= V; i++) {
        if (i == K) continue;
        dist[i] = INF;
    } 
    
    pq.push({dist[K], K});
    
    while (!pq.empty()) {
        int curVertex = pq.top().second;
        int curDistinPQ = pq.top().first;

        pq.pop();

        if (curDistinPQ > dist[curVertex]) continue;

        for (const auto& v : vertex[curVertex]) {
            int nextVertex = v.second;
            int nextDist = v.first + curDistinPQ;

            if (nextDist < dist[nextVertex]) {
                dist[nextVertex] = nextDist;
                pq.push({nextDist, nextVertex});
            }
            
        }

    }

    for (int i = 1; i <= V; i++) {
        if (dist[i] == INF) {
            cout << "INF\n";
        } 
        
        else {
            cout << dist[i] << '\n';
        } 
    }

    return 0;
}