#include <iostream>
#include <queue>

using namespace std;


int main() {
    int t;

    cin >> t;

    for (int i = 0; i < t; i++) {
        int n, m, cnt = 0;
        queue<pair<int, int>> q;
        priority_queue<int> pq;

        cin >> n >> m;
        
        for (int j = 0; j < n; j++) {
            int ipt;
            cin >> ipt;
            q.push({j, ipt});
            pq.push(ipt);
        }

        while (!q.empty()) {
            int ord, ipt;

            ord = q.front().first;
            ipt = q.front().second;

            if (ipt == pq.top()) {
                q.pop();
                pq.pop();
                cnt ++;
                if (ord == m)
                    break;
            }
            else {
                q.pop();
                q.push({ord, ipt});
            }
            
        }
        
        cout << cnt << '\n';
    }

    return 0;
}