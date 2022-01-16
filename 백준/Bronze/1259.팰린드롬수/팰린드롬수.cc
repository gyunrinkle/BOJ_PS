#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {

    bool bIterationTrigger = true;
    string str, strReverse;

    while (bIterationTrigger) {
        cin >> str;

        if (str == "0") {
            bIterationTrigger = false;
            continue;
        }

        strReverse = str;

        reverse(strReverse.begin(), strReverse.end());

        if (str == strReverse)
            cout << "yes" << endl;
        else
            cout << "no" << endl;

    }
    
    return 0;
}