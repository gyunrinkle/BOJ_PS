#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n;
    queue<int> q;
    
    cin >> n;

    for (int i = 1; i <= n; i++)
        q.push(i);
    
    while (!q.empty()) {
        if (q.size() == 1)
            break;
        
        q.pop();

        if (q.size() == 1)
            break;
        
        int tmp = q.front();
        q.pop();
        q.push(tmp);
    }

    cout << q.front() << '\n';
    
    q.pop();

    return 0;
}