#include <iostream>
#include <stack>
#include <vector>

using namespace std;

#define MAX 100000

int main() {

    int n, cnt = 0;
    int sequence[MAX];
    stack<int> s;
    vector<char> v;

    cin >> n;
    
    for(int i = 0; i < n; i++) {

        cin >> sequence[i];
    }

    s.push(cnt);

    for(int i = 0; i < n; i++) {
        
        bool bIterationTrigger = true;

        while(bIterationTrigger) {
            
            if(sequence[i] == s.top()) {
                s.pop();
                v.push_back('-');
                bIterationTrigger = false;
                continue;
            }

            if(sequence[i] > s.top()) {
                cnt++;
                s.push(cnt);
                v.push_back('+');
                continue;
            }

            if(sequence[i] < s.top()) {
                cout << "NO\n";
                return 0;
            }
            
        }

    }

    for(auto& i : v)
        cout << i << '\n';
    return 0;
}