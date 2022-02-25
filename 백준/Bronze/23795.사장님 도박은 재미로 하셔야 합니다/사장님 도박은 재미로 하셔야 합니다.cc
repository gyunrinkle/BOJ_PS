#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, summation = 0;
    bool iteration_trigger = true;
    while (iteration_trigger) {
        cin >> n;
        if (n == -1) {
            iteration_trigger = false;
            continue;
        }
        summation += n;
    }
    cout << summation << '\n';
    return 0;
}