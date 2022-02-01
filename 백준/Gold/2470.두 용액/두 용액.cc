#include <iostream>
#include <algorithm>
#define endl '\n'

using namespace std;

const int MAX = 100'000;
int N;
int values[MAX];

void Input() {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> values[i];
}

void Solve() {
    int s, e, m, ans_val1, ans_val2, ans_sum, summation;
    sort(&values[0], &values[0] + N);
    s = 0;
    e = N - 1;
    ans_val1 = values[s], ans_val2 = values[e];
    ans_sum = ans_val1 + ans_val2;
    while (s < e) {
        summation = values[s] + values[e];
        if (summation == 0) {
            ans_val1 = values[s], ans_val2 = values[e];
            break;
        }

        if (abs(ans_sum) > abs(summation)) {
                ans_sum = summation;
                ans_val1 = values[s], ans_val2 = values[e];
        }

        if (summation > 0) {
            e--;
            continue;
        }
        
        if (summation < 0) {
            s++;
            continue;
        }
    }

    cout << ans_val1 << ' ' << ans_val2 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    // freopen("input.txt", "r", stdin);
    Input();
    Solve();
    return 0;
}