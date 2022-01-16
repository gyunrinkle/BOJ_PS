#include <iostream>

using namespace std;

int main() {
    int t;
    int apartment[15][15] = {0,};
    
    cin >> t;

    for (int i = 1; i <= 14; i++) { //0층 1호 ~ 14호
        apartment[0][i] = i;
    }

    for (int i = 1; i <=14; i++) {
        for (int j = 1; j <=14; j++) {
            if (j == 1) {
                apartment[i][j] = apartment[i - 1][j];
                continue;
            }
            apartment[i][j] = apartment[i][j - 1] + apartment[i - 1][j];
        }
    }

    for (int i = 0; i < t; i++) {
        int k, n;
        cin >> k;
        cin >> n;
        if (apartment[k][n] != 0) {
            cout << apartment[k][n] << '\n';
        }
    }
    return 0;
}