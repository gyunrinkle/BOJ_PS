#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int N;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        pq.push({x, y});
    }
    
    for (int i = 0; i < N; i++) {
        cout << pq.top().first << ' ' << pq.top().second << '\n';
        pq.pop();
    }

    return 0;
}