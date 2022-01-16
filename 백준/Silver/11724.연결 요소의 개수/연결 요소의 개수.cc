#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX_LEN = 10001;
int N, M, cnt = 0;
int isVisited[MAX_LEN] = {0,};
vector<int> adjacent_lists[MAX_LEN + 1];

void bfs(int start) {
    queue<int> q;

    if (!isVisited[start]) {
        q.push(start);
        cnt++;
    }
    
    while (!q.empty()) {
        int curVertex = q.front();
        q.pop();
        if (!isVisited[curVertex]) {
            isVisited[curVertex] = 1;
            for (const auto& i : adjacent_lists[curVertex]) {
                if (!isVisited[i]) {
                    q.push(i);
                }
            }
        }
    }
}

int main() {
    cin  >> N >> M;
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        adjacent_lists[u].push_back(v);
        adjacent_lists[v].push_back(u);
    }
    for (int i = 1; i <= N; i++) bfs(i);
    cout << cnt << '\n';
    return 0;
}