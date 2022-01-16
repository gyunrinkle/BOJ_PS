#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int k, n, maximum;

vector<int> lines;

bool isPossible(long long mid) {

    int cnt = 0;

    for(auto& i : lines)
        cnt += i / mid;

    if(cnt >= n)
        return true;
    
    return false;

}

void binarySearch(long long low, long long high) {
    

    if(low > high)
        return;

    long long mid = (low + high) / 2;

    if(isPossible(mid)) {

        if(mid > maximum) {
            maximum = mid;
        }

        binarySearch(mid + 1, high);
    }
    else
        binarySearch(low, mid - 1);
    
}

int main() {

    cin >> k >> n;

    for(int i = 0; i < k; i++) {

        int lan;
        cin >> lan;
        lines.push_back(lan);
    }

    sort(lines.begin(), lines.end());

    binarySearch(1, lines.back());

    cout << maximum << '\n';

    return 0;
}