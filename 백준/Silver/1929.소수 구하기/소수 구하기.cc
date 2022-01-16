#include <iostream>

using namespace std;

#define MAX 1000001

int main() {

    int arr[MAX];
    int m, n;
    fill_n(arr, MAX, 1);

    cin >> m >> n;

    arr[1] = 0;

    for(int i = 2; i <= n; i++) {
        
        int j = 1;
        bool bIterationTrigger = true;

        while(bIterationTrigger) {

            j++;
            int k = i * j;

            if(k <= n && arr[k] == 1) {
                arr[k] = 0;
            }

            else if(k > n)
                bIterationTrigger = false;
                continue;

        }
    }

    for(int i = m; i <= n; i++) {

        if(arr[i])
            cout << i << '\n';
    }

    return 0;
}