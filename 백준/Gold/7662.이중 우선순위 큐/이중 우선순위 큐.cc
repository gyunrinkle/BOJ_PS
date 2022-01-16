#include <iostream>
#include <map>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T, k;
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    map<int, int> mp;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> k;
        for (int j = 0; j < k; j++) {
            char c;
            int e;
            cin >> c >> e;
            if (c == 'I') {
                maxHeap.push(e);
                minHeap.push(e);
                mp[e]++;
            }
            else if (c == 'D') {
                if (e == 1) { // 가장 큰 값 삭제
                    while (!maxHeap.empty() && mp[maxHeap.top()] == 0) maxHeap.pop(); // map 기록해둔 count가 있을 때까지 pop한다.
                    if (!maxHeap.empty()) { // pop하다가 남는 게 있으면 그게 진짜 max
                        mp[maxHeap.top()]--;
                        maxHeap.pop();
                    }
                }
                else if (e == -1) { //가장 작은 값 삭제
                    while (!minHeap.empty() && mp[minHeap.top()] == 0) minHeap.pop(); // map 기록해둔 count가 있을 때까지 pop한다.
                    if (!minHeap.empty()) { // pop하다가 남는 게 있으면 그게 진짜 min
                        mp[minHeap.top()]--;
                        minHeap.pop();
                    }
                }
            }
        }
        // 마지막으로 map 기록해둔 count를 기반으로 각 maxHeap, minHeap들을 비워줄 수 있을 때까지 비워 준다.
        while (!maxHeap.empty() && mp[maxHeap.top()] == 0) maxHeap.pop();
        while (!minHeap.empty() && mp[minHeap.top()] == 0) minHeap.pop();
        //결과값 출력
        if (maxHeap.empty() && minHeap.empty()){
            cout << "EMPTY\n";
        } 
        else {
            cout << maxHeap.top() << ' ' << minHeap.top() << '\n';
        }
        //각 stl 초기화 해주기
        mp.clear();
        while(!maxHeap.empty()) maxHeap.pop();
        while(!minHeap.empty()) minHeap.pop();
    }
    
    return 0;
}

