#include <iostream>

using namespace std;


int main() {
    bool bIterationTrigger = true;

    while (bIterationTrigger) {
        int a, b, c, tempMax, maximum;
        cin >> a >> b >> c;

        if (a == 0 && b == 0 && c == 0) {
            bIterationTrigger = false;
            continue;
        }
        
        // a < b < c, bubble sort 과정과 동일, 큰 거를 일단 c로 보내고, 다시 처음부터 훑으면서 그 다음 큰 거를 b로 보낸다.
        if (a > b) swap(a, b);
        if (b > c) swap(b ,c);
        if (a > b) swap(a, b);

        if (c * c == a * a + b * b){
            cout << "right\n";
        } 
        else {
            cout << "wrong\n";
        }

    }

    return 0;
}