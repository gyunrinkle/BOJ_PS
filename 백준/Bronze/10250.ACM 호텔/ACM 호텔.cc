#include <iostream>

using namespace std;

int main() {
    int t;

    cin >> t;
    for (int i = 0; i < t;i ++) {
        int h, w, n;
        int level;

        cin >> h >> w >> n;
        level = n % h;

        if (level == 0) { // 나눠 떨어진다.
            cout << h << (n / h) / 10 << (n / h) % 10 << '\n';
            continue;
        }

        cout << level << (n / h + 1) / 10 << (n / h + 1) % 10 << '\n';
    }

    return 0;
    
}
