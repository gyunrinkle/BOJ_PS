#include <bits/stdc++.h>
using namespace std;
const int MAX = 100000;//vertex개수 최대값
int V, max_v, tree_diameter = 0;//vertex 개수, 트리의 지름
vector<pair<int, int>> tree[MAX + 1];
bool is_visited[MAX + 1] = {false, };

void Input() {
    int v, u, e;
    cin >> V;
    for (int i = 1; i <= V; i++) {
        cin >> v;
        while (cin >> u && u != -1) {
            cin >> e;
            tree[v].push_back({u, e}); // v - u 는 e의 가중치로 연결된다.
        }
    }
}

void DFS(int start_v, int sum) {
    if (is_visited[start_v]) return;
    is_visited[start_v] = true;
    if (sum > tree_diameter){
        tree_diameter = sum;
        max_v = start_v;
    } 
    for (const auto& nv : tree[start_v]) {
        if (is_visited[nv.first]) continue;
        DFS(nv.first, sum + nv.second);
    }
}

void Solve() {
    Input();
    DFS(1, 0);
    fill_n(is_visited, MAX + 1, false);
    DFS(max_v, 0);
    cout << tree_diameter << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    Solve();
    return 0;
}